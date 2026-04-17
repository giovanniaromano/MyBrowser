/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage;
    QGridLayout *gridLayout_2;
    QPushButton *backButton0;
    QPushButton *refreshButton0;
    QPushButton *forwardButton0;
    QLineEdit *urlEdit0;
    QPushButton *goButton0;
    QWebEngineView *webEngineView0;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 580);

        //MainWindow->setWindowFlags(Qt::FramelessWindowHint);
        //MainWindow->setMaximumSize(QSize(16777215, 777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        //centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        //tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menuBar);
        MainWindow->setWindowTitle(QCoreApplication::translate("MyBrowser", "MyBrowser", nullptr));
        QMetaObject::connectSlotsByName(MainWindow);

    } // setupUi


};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
