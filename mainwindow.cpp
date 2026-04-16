#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolButton>
#include <QTabBar>
#include <QWebEngineCookieStore>
#include <QWebEngineProfile>
#include <qcustomtabwidget.h>
#include <QShortcut>


using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->on_newTabButton_clicked();
    QPushButton* moreTabsButton = new QPushButton( ui->tabWidget);
    moreTabsButton->setObjectName("moreTabsButton");
    moreTabsButton->setText("+");
    QObject::connect(moreTabsButton, &QPushButton::clicked, this,  &MainWindow::on_newTabButton_clicked);
    ui->tabWidget->setCornerWidget(moreTabsButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goButton_clicked()
{

    int currentIndex = ui->tabWidget->currentIndex();
    //Nel  tab corrente, si devono prendere il campo url e l'oggetto web engine
    QWebEngineView *webEngine =  ui->centralWidget->findChild<QWebEngineView*>(QString::fromStdString("webEngineView"+ std::to_string(currentIndex)));

    QCustomPushButton *goButton =  ui->centralWidget->findChild<QCustomPushButton*>(QString::fromStdString("goButton"+ std::to_string(currentIndex)));
         QLineEdit *lineEdit = ui->centralWidget->findChild<QLineEdit*>(QString::fromStdString("urlEdit"+ std::to_string(currentIndex)));
    if(!(goButton == NULL ||lineEdit == NULL  || webEngine == NULL )){
       QString url = lineEdit->text();
        if(!url.contains("http") && !url.contains("ftp")){
            url = "https://" +url;
        }
        webEngine->load(url);
    }
}



void MainWindow::on_webEngineView_loadFinished(bool arg1)
{
    if(arg1){
        ui->statusbar->showMessage("Load successful.");
        int currentIndex = ui->tabWidget->currentIndex();
        //Nel  tab corrente, si devono prendere il campo url e l'oggetto web engine

        QWebEngineView *webEngine =  ui->centralWidget->findChild<QWebEngineView*>(QString::fromStdString("webEngineView"+ std::to_string(currentIndex)));
        QLineEdit *lineEdit = ui->centralWidget->findChild<QLineEdit*>(QString::fromStdString("urlEdit"+ std::to_string(currentIndex)));
        if(!(webEngine == NULL || lineEdit == NULL)){
            lineEdit->setText(lineEdit->text());
            QString tabTitle =webEngine->title();
            if(tabTitle.length() > 20){
                tabTitle.truncate(20);
            }
            ui->tabWidget->setTabText(currentIndex, tabTitle);
            QIcon icon = webEngine->icon();
            ui->tabWidget->setTabIcon(currentIndex, webEngine->icon());

        }

    }else{
        ui->statusbar->showMessage("Load unsuccessful.");
    }
}

void MainWindow::webEngineView_setIcon(QIcon icon)
{
   int index = ui->tabWidget->currentIndex();
     ui->tabWidget->setTabIcon(index, icon);
}


    void MainWindow::webEngineView_setTitle(const QString &title)
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->setTabText(index, title);
}

void MainWindow::on_newTabButton_clicked()
{
        QCustomTabWidget* tabWidgetPage = new QCustomTabWidget();

        //Si setta ll'indice
        int newIndex = ui->tabWidget->currentIndex()+1;
        tabWidgetPage->setCurrentIndex(newIndex);
        tabWidgetPage->setIndex(newIndex);
        tabWidgetPage->setObjectName("tab"+std::to_string(newIndex));

        QGridLayout* gridLayout = new QGridLayout(tabWidgetPage);
        gridLayout->setObjectName( "gridLayout"+ std::to_string(newIndex));
        QCustomPushButton* backButton = new QCustomPushButton(tabWidgetPage);
        backButton->setText("<");
        backButton->setObjectName("backButton"+std::to_string(newIndex));
        gridLayout->addWidget(backButton, 0, 0, 1, 1);

        QCustomPushButton* refreshButton = new QCustomPushButton(tabWidgetPage);
        refreshButton->setText("Refresh");
        refreshButton->setObjectName("refreshButton"+std::to_string(newIndex));
        gridLayout->addWidget(refreshButton, 0, 1, 1, 1);

        QCustomPushButton* forwardButton = new QCustomPushButton(tabWidgetPage);
        forwardButton->setObjectName("forwardButton"+std::to_string(newIndex));
        forwardButton->setText(">");
        gridLayout->addWidget(forwardButton, 0, 2, 1, 1);

        QLineEdit* urlEdit = new QLineEdit(tabWidgetPage);
        urlEdit->setObjectName("urlEdit"+std::to_string(newIndex));
        gridLayout->addWidget(urlEdit, 0, 3, 1, 1);

        QCustomPushButton* goButton = new QCustomPushButton(tabWidgetPage);
        goButton->setText("GO");
        goButton->setObjectName("goButton"+std::to_string(newIndex));
        gridLayout->addWidget(goButton, 0, 4, 1, 1);
        QMetaObject::Connection result = QObject::connect(goButton, &QCustomPushButton::clicked,
                                                          tabWidgetPage, &QCustomTabWidget::onButtonClicked);

        QWebEngineView* webEngineView = new QWebEngineView(tabWidgetPage);
        webEngineView->setObjectName("webEngineView"+std::to_string(newIndex));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webEngineView->sizePolicy().hasHeightForWidth());
        webEngineView->setSizePolicy(sizePolicy1);
        webEngineView->setLayoutDirection(Qt::LeftToRight);
        webEngineView->setAutoFillBackground(false);
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));


        result = QObject::connect(forwardButton, &QCustomPushButton::clicked,
                                                          webEngineView, &QWebEngineView::forward);
        result = QObject::connect(backButton, &QCustomPushButton::clicked,
                                                           webEngineView, &QWebEngineView::back);

        //Per settare titolo e icona
        QIcon icon;
        result = QObject::connect(webEngineView, &QWebEngineView::iconChanged,
                                  tabWidgetPage,&QCustomTabWidget::on_webEngineView_changeIcon);
        result = QObject::connect(webEngineView, &QWebEngineView::titleChanged,
                                    tabWidgetPage,&QCustomTabWidget::on_webEngineView_changeTitle);

        gridLayout->addWidget(webEngineView, 1, 0, 1, 5);

        int index = ui->tabWidget->addTab(tabWidgetPage, "New page");
        tabWidgetPage->setCurrentIndex(index);
        ui->tabWidget->setCurrentIndex(index);

        ui->gridLayout->addWidget( ui->tabWidget, 2, 0, 1, 1);

        QWidget::setTabOrder(backButton, refreshButton);
        QWidget::setTabOrder(refreshButton, forwardButton);
        QWidget::setTabOrder(forwardButton, goButton);
        QWidget::setTabOrder(goButton, urlEdit);


        QShortcut *returnShortcut = new QShortcut(QKeySequence("Return"), tabWidgetPage);
        QObject::connect(returnShortcut, SIGNAL(activated()), goButton, SLOT(click()));

    }




