/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_Toolbar;
    QComboBox *comboDay;
    QPushButton *btnDeleteSelected;
    QPushButton *btnClearDay;
    QPushButton *btnClearWeek;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listDaily;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWeekly;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputTask;
    QPushButton *btnAdd;
    QHBoxLayout *layoutProgressDaily;
    QLabel *lblProgressDaily;
    QProgressBar *progressDaily;
    QHBoxLayout *layoutProgressWeekly;
    QLabel *lblProgressWeekly;
    QProgressBar *progressWeekly;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_Toolbar = new QHBoxLayout();
        horizontalLayout_Toolbar->setObjectName("horizontalLayout_Toolbar");
        comboDay = new QComboBox(centralwidget);
        comboDay->addItem(QString());
        comboDay->addItem(QString());
        comboDay->addItem(QString());
        comboDay->addItem(QString());
        comboDay->addItem(QString());
        comboDay->addItem(QString());
        comboDay->addItem(QString());
        comboDay->setObjectName("comboDay");

        horizontalLayout_Toolbar->addWidget(comboDay);

        btnDeleteSelected = new QPushButton(centralwidget);
        btnDeleteSelected->setObjectName("btnDeleteSelected");

        horizontalLayout_Toolbar->addWidget(btnDeleteSelected);

        btnClearDay = new QPushButton(centralwidget);
        btnClearDay->setObjectName("btnClearDay");

        horizontalLayout_Toolbar->addWidget(btnClearDay);

        btnClearWeek = new QPushButton(centralwidget);
        btnClearWeek->setObjectName("btnClearWeek");

        horizontalLayout_Toolbar->addWidget(btnClearWeek);


        verticalLayout->addLayout(horizontalLayout_Toolbar);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listDaily = new QListWidget(tab);
        listDaily->setObjectName("listDaily");

        verticalLayout_2->addWidget(listDaily);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWeekly = new QListWidget(tab_2);
        listWeekly->setObjectName("listWeekly");

        verticalLayout_3->addWidget(listWeekly);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        inputTask = new QLineEdit(centralwidget);
        inputTask->setObjectName("inputTask");

        horizontalLayout->addWidget(inputTask);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");

        horizontalLayout->addWidget(btnAdd);


        verticalLayout->addLayout(horizontalLayout);

        layoutProgressDaily = new QHBoxLayout();
        layoutProgressDaily->setObjectName("layoutProgressDaily");
        lblProgressDaily = new QLabel(centralwidget);
        lblProgressDaily->setObjectName("lblProgressDaily");
        lblProgressDaily->setMinimumSize(QSize(140, 0));

        layoutProgressDaily->addWidget(lblProgressDaily);

        progressDaily = new QProgressBar(centralwidget);
        progressDaily->setObjectName("progressDaily");
        progressDaily->setValue(0);
        progressDaily->setTextVisible(false);

        layoutProgressDaily->addWidget(progressDaily);


        verticalLayout->addLayout(layoutProgressDaily);

        layoutProgressWeekly = new QHBoxLayout();
        layoutProgressWeekly->setObjectName("layoutProgressWeekly");
        lblProgressWeekly = new QLabel(centralwidget);
        lblProgressWeekly->setObjectName("lblProgressWeekly");
        lblProgressWeekly->setMinimumSize(QSize(140, 0));

        layoutProgressWeekly->addWidget(lblProgressWeekly);

        progressWeekly = new QProgressBar(centralwidget);
        progressWeekly->setObjectName("progressWeekly");
        progressWeekly->setValue(0);
        progressWeekly->setTextVisible(false);

        layoutProgressWeekly->addWidget(progressWeekly);


        verticalLayout->addLayout(layoutProgressWeekly);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FocusFlow - Task Manager", nullptr));
        comboDay->setItemText(0, QCoreApplication::translate("MainWindow", "Poniedzia\305\202ek", nullptr));
        comboDay->setItemText(1, QCoreApplication::translate("MainWindow", "Wtorek", nullptr));
        comboDay->setItemText(2, QCoreApplication::translate("MainWindow", "\305\232roda", nullptr));
        comboDay->setItemText(3, QCoreApplication::translate("MainWindow", "Czwartek", nullptr));
        comboDay->setItemText(4, QCoreApplication::translate("MainWindow", "Pi\304\205tek", nullptr));
        comboDay->setItemText(5, QCoreApplication::translate("MainWindow", "Sobota", nullptr));
        comboDay->setItemText(6, QCoreApplication::translate("MainWindow", "Niedziela", nullptr));

        btnDeleteSelected->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 zaznaczone", nullptr));
        btnClearDay->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207 ten dzie\305\204", nullptr));
        btnClearWeek->setText(QCoreApplication::translate("MainWindow", "Zresetuj ca\305\202y tydzie\305\204", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Jutro", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tydzie\305\204", nullptr));
        inputTask->setPlaceholderText(QCoreApplication::translate("MainWindow", "Wpisz nowe zadanie...", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Dodaj zadanie", nullptr));
        lblProgressDaily->setText(QCoreApplication::translate("MainWindow", "Jutro: 0% (0/0)", nullptr));
        lblProgressWeekly->setText(QCoreApplication::translate("MainWindow", "Tydzie\305\204: 0% (0/0)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
