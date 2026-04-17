#include "qcustomtab.h"

#include <qforeach.h>
#include <qwebengineview.h>
#include <qobject.h>
#include <qlineedit.h>
#include<QDebug>
#include <qtabbar.h>




QCustomTab::QCustomTab(QWidget *parent)
    : QWidget{parent}

{

}




QObject* QCustomTab::getChildWidget(QString widgetName)
{
    QList<QObject*> widgets = this->children();
    QListIterator<QObject*> i(widgets);
    QObject* trovato = NULL;

    while (i.hasNext()) {
        QObject* o = i.next();
        if(o->objectName().contains(widgetName)){
            trovato = o;
        }

    }
    return  trovato;
}




void QCustomTab::onButtonClicked(){

    //E' stato cliccato il pulsante "GO"
    //Di conseguenza, ooccorrre prendere la webview contenuta nello stesso tab del pulsante, o per lo meno quella corrente, e valorizzarla con il contenuto relativo a

    QList<QObject* > widgets =  this->children() ;

    QListIterator<QObject*> i(widgets);
    QObject* trovatoUrlField = NULL;
    QObject* trovatoWebEngine = NULL;
    while (i.hasNext()) {
        QObject* o = i.next();
        if(o->objectName().contains("urlEdit")){
            trovatoUrlField = o;
        }
        if(o->objectName().contains("webEngineView")){
            trovatoWebEngine = o;
        }
    }
    if(trovatoUrlField != NULL && trovatoWebEngine != NULL){
        QString url = ((QLineEdit*)trovatoUrlField)->text();
        QWebEngineView* webEngineView = (QWebEngineView*)trovatoWebEngine;
        webEngineView->load(QUrl::fromUserInput(url));

        webEngineView->show();
    }

}
//Si dovrebbe accedere
void  QCustomTab::on_webEngineView_loadStarted()
{

}


void QCustomTab::webEngineView_setIcon(QIcon icon)
{

   container->setTabIcon(index, icon);
}


void QCustomTab::webEngineView_setTitle(const QString &title)
{

    QString truncated = title;
    if(truncated.length() > 20){
        truncated.truncate(20);
    }
    container->setTabText(index, truncated);
}




void QCustomTab::setIndex(int index)
{
    this->index = index;
}

void  QCustomTab::setContainer(QTabWidget* container){
    this->container = container;
}

QTabWidget* QCustomTab::getContainer(){
    return  this->container;
}





