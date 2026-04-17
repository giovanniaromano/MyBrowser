#include "FixedWidthString.cpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolButton>
#include <QTabBar>
#include <QWebEngineCookieStore>
#include <QWebEngineProfile>
#include <qcustomtab.h>
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

        int currentIndex = ui->tabWidget->currentIndex();
        //Nel  tab corrente, si devono prendere il campo url e l'oggetto web engine
        QWebEngineView *webEngine =  ui->centralWidget->findChild<QWebEngineView*>(QString::fromStdString("webEngineView"+ std::to_string(currentIndex)));

        this->ui->tabWidget->setTabIcon(currentIndex, webEngine->icon());
        QString title = webEngine->title();
        if(title.length() > 20){
            title.truncate(20);
        }
        this->ui->tabWidget->setTabText(currentIndex, title);
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
    QString truncated = title;
    if(truncated.length() > 20){
        truncated.truncate(20);
    }
    ui->tabWidget->setTabText(index, truncated);
}

void MainWindow::on_newTabButton_clicked()
{
    QCustomTab* tabWidgetPage = new QCustomTab(ui->tabWidget);
    tabWidgetPage->setContainer(ui->tabWidget);

    //Si setta ll'indice
    int newIndex = ui->tabWidget->currentIndex()+1;

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
                                                      tabWidgetPage, &QCustomTab::onButtonClicked);



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

    int index = ui->tabWidget->addTab(tabWidgetPage, "New page");

    ui->tabWidget->setCurrentIndex(index);

    result = QObject::connect(forwardButton, &QCustomPushButton::clicked,
                              webEngineView, &QWebEngineView::forward);
    result = QObject::connect(backButton, &QCustomPushButton::clicked,
                              webEngineView, &QWebEngineView::back);




    result = QObject::connect(webEngineView, &QWebEngineView::iconChanged,
                              tabWidgetPage, &QCustomTab::webEngineView_setIcon);
    result = QObject::connect(webEngineView, &QWebEngineView::titleChanged,
                              tabWidgetPage, &QCustomTab::webEngineView_setTitle);



    gridLayout->addWidget(webEngineView, 1, 0, 1, 5);



    ui->gridLayout->addWidget( ui->tabWidget, 2, 0, 1, 1);

    QWidget::setTabOrder(backButton, refreshButton);
    QWidget::setTabOrder(refreshButton, forwardButton);
    QWidget::setTabOrder(forwardButton, goButton);
    QWidget::setTabOrder(goButton, urlEdit);


    QShortcut *returnShortcut = new QShortcut(QKeySequence("Return"), tabWidgetPage);
    QObject::connect(returnShortcut, SIGNAL(activated()), goButton, SLOT(click()));

}




