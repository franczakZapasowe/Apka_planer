#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool initDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");

    if (!db.open()) {
        qDebug() << "Błąd połączenia z bazą:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;

   // query.exec("DROP TABLE IF EXISTS tasks");

    return query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "content TEXT, "
                      "is_done INTEGER, "
                      "day_id INTEGER)"); // 0 = Jutro, 1 = Pon, 2 = Wt, ..., 7 = Nd
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString darkStyle = R"(
        QMainWindow {
            background-color: #1e1e2e;
        }
        QLabel {
            color: #cdd6f4;
            font-size: 13px;
        }
        QLineEdit {
            background-color: #313244;
            color: #cdd6f4;
            border: 1px solid #45475a;
            border-radius: 6px;
            padding: 6px;
            font-size: 14px;
        }
        QPushButton {
            background-color: #89b4fa;
            color: #1e1e2e;
            font-weight: bold;
            border-radius: 6px;
            padding: 8px 16px;
        }
        QPushButton:hover {
            background-color: #b4befe;
        }
        QPushButton:pressed {
            background-color: #74c7ec;
        }
        QListWidget {
            background-color: #313244;
            color: #cdd6f4;
            border: 1px solid #45475a;
            border-radius: 8px;
            outline: none;
            font-size: 14px;
        }
        QListWidget::item {
            padding: 10px;
            border-bottom: 1px solid #45475a;
        }
        QListWidget::item:selected {
            background-color: #45475a;
            color: #89b4fa;
        }
        QListWidget::indicator {
            width: 18px;
            height: 18px;
            border-radius: 4px;
            border: 2px solid #89b4fa;
        }
        QListWidget::indicator:checked {
            background-color: #89b4fa;
            image: url(); /* Tu normalnie daje się ikonę ptaszka, na razie wypełniamy kolorem */
        }
        QTabWidget::pane {
            border: none;
            background-color: transparent;
        }
        QTabBar::tab {
            background: #313244;
            color: #a6adc8;
            padding: 8px 20px;
            border-top-left-radius: 6px;
            border-top-right-radius: 6px;
            margin-right: 4px;
        }
        QTabBar::tab:selected {
            background: #89b4fa;
            color: #1e1e2e;
            font-weight: bold;
        }
        QComboBox {
            background-color: #313244;
            color: #cdd6f4;
            border: 1px solid #45475a;
            border-radius: 6px;
            padding: 6px;
            font-size: 14px;
        }
        QComboBox::drop-down {
            border: none;

QProgressBar {
            border: 1px solid #45475a;
            border-radius: 6px;
            background-color: #1e1e2e;
            height: 14px;
        }
        QProgressBar::chunk {
            border-radius: 5px;
        }
        #progressDaily::chunk {
            background-color: #a6e3a1;
        }
        #progressWeekly::chunk {
            background-color: #cba6f7;
        }
        }
    )";
    a.setStyleSheet(darkStyle);
    // ----------------------------------

    if (!initDatabase()) {
        qDebug() << "Nie udało się zainicjować bazy danych!";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
