#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Wczytujemy zadania z bazy do list zaraz po uruchomieniu okna
    loadTasks();

    // 2. Łączymy sygnał z list (ktoś kliknął checkbox) z naszą funkcją
    connect(ui->listDaily, &QListWidget::itemChanged, this, &MainWindow::onListItemChanged);
    connect(ui->listWeekly, &QListWidget::itemChanged, this, &MainWindow::onListItemChanged);
    connect(ui->comboDay, &QComboBox::currentIndexChanged, this, &MainWindow::loadTasks);

    // 3. Pokazujemy statystyki na start
    updateSummary();

    this->setWindowTitle("FocusFlow - Task Manager");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- FUNKCJA WCZYTUJĄCA DANE Z BAZY ---
void MainWindow::loadTasks() {
    ui->listDaily->blockSignals(true);
    ui->listWeekly->blockSignals(true);

    ui->listDaily->clear();
    ui->listWeekly->clear();

    // Pobieramy zaznaczony dzień z ComboBoxa (indeks 0 to Poniedziałek, więc dajemy +1)
    int selectedDayId = ui->comboDay->currentIndex() + 1;

    QSqlQuery query("SELECT id, content, is_done, day_id FROM tasks");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString content = query.value(1).toString();
        bool isDone = query.value(2).toBool();
        int dayId = query.value(3).toInt();

        QListWidgetItem *item = new QListWidgetItem(content);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(isDone ? Qt::Checked : Qt::Unchecked);
        item->setData(Qt::UserRole, id);

        // Rozdzielamy: 0 idzie do "Jutro", reszta jest filtrowana dla zakładki "Tydzień"
        if (dayId == 0) {
            ui->listDaily->addItem(item);
        } else if (dayId == selectedDayId) {
            // Dodajemy do listy tylko zadania z wybranego dnia
            ui->listWeekly->addItem(item);
        }
    }

    ui->listDaily->blockSignals(false);
    ui->listWeekly->blockSignals(false);
}

// --- DODAWANIE ZADANIA ---
void MainWindow::on_btnAdd_clicked() {
    QString text = ui->inputTask->text();
    if (text.isEmpty()) return;

    // Jeżeli jesteśmy na zakładce 0 (Jutro), day_id = 0
    // Jeżeli jesteśmy na zakładce 1 (Tydzień), bierzemy indeks z ComboBoxa + 1
    int dayId = 0;
    if (ui->tabWidget->currentIndex() == 1) {
        dayId = ui->comboDay->currentIndex() + 1;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO tasks (content, is_done, day_id) VALUES (:content, 0, :dayId)");
    query.bindValue(":content", text);
    query.bindValue(":dayId", dayId);

    if (query.exec()) {
        ui->inputTask->clear();
        loadTasks();
        updateSummary();
    }
}

// --- ODZNACZANIE ZADANIA (AKTUALIZACJA BAZY) ---
void MainWindow::onListItemChanged(QListWidgetItem *item) {
    // Wyciągamy nasze zapisane ID
    int id = item->data(Qt::UserRole).toInt();
    int done = (item->checkState() == Qt::Checked) ? 1 : 0;

    QSqlQuery query;
    query.prepare("UPDATE tasks SET is_done = :done WHERE id = :id");
    query.bindValue(":done", done);
    query.bindValue(":id", id);
    query.exec();

    updateSummary(); // Przeliczamy statystyki po kliknięciu
}

// --- PODSUMOWANIE (STATYSTYKI) ---
void MainWindow::updateSummary() {
    // --- 1. STATYSTYKI DLA "JUTRA" (day_id = 0) ---
    QSqlQuery queryDaily("SELECT is_done FROM tasks WHERE day_id = 0");
    int totalDaily = 0;
    int completedDaily = 0;

    while (queryDaily.next()) {
        totalDaily++;
        if (queryDaily.value(0).toInt() == 1) completedDaily++;
    }

    int percentDaily = (totalDaily == 0) ? 0 : (completedDaily * 100) / totalDaily;
    ui->progressDaily->setValue(percentDaily);
    // TERAZ ZMIENIAMY TEKST W LABELU:
    ui->lblProgressDaily->setText(QString("Jutro: %1% (%2/%3)").arg(percentDaily).arg(completedDaily).arg(totalDaily));


    // --- 2. STATYSTYKI DLA "TYGODNIA" (day_id > 0) ---
    QSqlQuery queryWeekly("SELECT is_done FROM tasks WHERE day_id > 0");
    int totalWeekly = 0;
    int completedWeekly = 0;

    while (queryWeekly.next()) {
        totalWeekly++;
        if (queryWeekly.value(0).toInt() == 1) completedWeekly++;
    }

    int percentWeekly = (totalWeekly == 0) ? 0 : (completedWeekly * 100) / totalWeekly;
    ui->progressWeekly->setValue(percentWeekly);
    // TERAZ ZMIENIAMY TEKST W LABELU:
    ui->lblProgressWeekly->setText(QString("Tydzień: %1% (%2/%3)").arg(percentWeekly).arg(completedWeekly).arg(totalWeekly));
}


void MainWindow::on_btnDeleteSelected_clicked() {
    // Sprawdzamy, która lista jest aktywna
    QListWidget* currentList = (ui->tabWidget->currentIndex() == 0) ? ui->listDaily : ui->listWeekly;
    QListWidgetItem* item = currentList->currentItem();

    if (!item) return; // Jeśli nic nie wybrano, nic nie rób

    int id = item->data(Qt::UserRole).toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM tasks WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        loadTasks();
        updateSummary();
    }
}

void MainWindow::on_btnClearDay_clicked() {
    int dayId = (ui->tabWidget->currentIndex() == 0) ? 0 : (ui->comboDay->currentIndex() + 1);

    // UX: Zapytaj użytkownika, czy na pewno
    auto reply = QMessageBox::question(this, "Potwierdzenie", "Czy na pewno usunąć wszystkie zadania z tego dnia?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;

    QSqlQuery query;
    query.prepare("DELETE FROM tasks WHERE day_id = :dayId");
    query.bindValue(":dayId", dayId);
    query.exec();

    loadTasks();
    updateSummary();
}


void MainWindow::on_btnClearWeek_clicked() {
    auto reply = QMessageBox::question(this, "Reset Tygodnia", "Czy na pewno wyczyścić CAŁY tydzień?",
                                       QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;

    QSqlQuery query;
    query.exec("DELETE FROM tasks WHERE day_id > 0");

    loadTasks();
    updateSummary();
}

void MainWindow::archiveCompleted() {
    QSqlQuery query;
    // Usuwa tylko to, co odhaczyłeś jako zrobione
    query.exec("DELETE FROM tasks WHERE is_done = 1");
    loadTasks();
    updateSummary();
}
