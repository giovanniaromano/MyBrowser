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
        MainWindow->setMaximumSize(QSize(16777215, 777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidgetPage = new QWidget();
        tabWidgetPage->setObjectName("tabWidgetPage");
        gridLayout_2 = new QGridLayout(tabWidgetPage);
        gridLayout_2->setObjectName("gridLayout_2");
        backButton0 = new QPushButton(tabWidgetPage);
        backButton0->setObjectName("backButton0");

        gridLayout_2->addWidget(backButton0, 0, 0, 1, 1);

        refreshButton0 = new QPushButton(tabWidgetPage);
        refreshButton0->setObjectName("refreshButton0");

        gridLayout_2->addWidget(refreshButton0, 0, 1, 1, 1);

        forwardButton0 = new QPushButton(tabWidgetPage);
        forwardButton0->setObjectName("forwardButton0");

        gridLayout_2->addWidget(forwardButton0, 0, 2, 1, 1);

        urlEdit0 = new QLineEdit(tabWidgetPage);
        urlEdit0->setObjectName("urlEdit0");

        gridLayout_2->addWidget(urlEdit0, 0, 3, 1, 1);

        goButton0 = new QPushButton(tabWidgetPage);
        goButton0->setObjectName("goButton0");

        gridLayout_2->addWidget(goButton0, 0, 4, 1, 1);

        webEngineView0 = new QWebEngineView(tabWidgetPage);
        webEngineView0->setObjectName("webEngineView0");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webEngineView0->sizePolicy().hasHeightForWidth());
        webEngineView0->setSizePolicy(sizePolicy1);
        webEngineView0->setLayoutDirection(Qt::LeftToRight);
        webEngineView0->setAutoFillBackground(false);
        webEngineView0->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_2->addWidget(webEngineView0, 1, 0, 1, 5);

        tabWidget->addTab(tabWidgetPage, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(backButton0, refreshButton0);
        QWidget::setTabOrder(refreshButton0, forwardButton0);
        QWidget::setTabOrder(forwardButton0, goButton0);
        QWidget::setTabOrder(goButton0, urlEdit0);

        retranslateUi(MainWindow);
        QObject::connect(backButton0, &QPushButton::clicked, backButton0, qOverload<>(&QPushButton::click));
        QObject::connect(refreshButton0, &QPushButton::clicked, webEngineView0, qOverload<>(&QWebEngineView::reload));
        QObject::connect(forwardButton0, &QPushButton::clicked, webEngineView0, qOverload<>(&QWebEngineView::forward));
        QObject::connect(backButton0, &QPushButton::clicked, webEngineView0, qOverload<>(&QWebEngineView::back));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        backButton0->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        refreshButton0->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        forwardButton0->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        goButton0->setText(QCoreApplication::translate("MainWindow", "GO", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage), QString());
    } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
