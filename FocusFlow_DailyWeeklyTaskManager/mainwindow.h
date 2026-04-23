#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked(); // Slot dla przycisku dodawania
    void onListItemChanged(QListWidgetItem *item); // Slot dla kliknięcia w checkbox
    void updateSummary(); // Funkcja licząca statystyki
    void on_btnDeleteSelected_clicked();
    void on_btnClearDay_clicked();
    void on_btnClearWeek_clicked();
private:
    Ui::MainWindow *ui;
    void loadTasks();
    void archiveCompleted();
};
#endif // MAINWINDOW_H
