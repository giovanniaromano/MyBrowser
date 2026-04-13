#include "qcustomtabwidget.h"

#include <qforeach.h>
#include <qwebengineview.h>
#include <qobject.h>
#include <qlineedit.h>




QCustomTabWidget::QCustomTabWidget(QTabWidget *parent)
    : QTabWidget{parent}
{

}




QObject* QCustomTabWidget::getChildWidget(QString widgetName)
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




void QCustomTabWidget::onButtonClicked(){

        //E' stato cliccato il pulsante "GO"
        //Di conseguenza, ooccorrre prendere la webview contenuta nello stesso tab del pulsante, o per lo meno quella corrente, e valorizzarla con il contenuto relativo a
        QObject widget;
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

            int currentIndex = this->currentIndex();
            this->setTabIcon(currentIndex,webEngineView->icon());
            this->setTabText(currentIndex,webEngineView->title());
            webEngineView->show();
        }

}
//Si dovrebbe accedere
void  QCustomTabWidget::on_webEngineView_loadStarted()
{

}


void  QCustomTabWidget::on_webEngineView_loadFinished(bool arg1)
{
    if(arg1){

        int currentIndex = this->currentIndex();
        this->setTabText(currentIndex, this->findChild<QWebEngineView*>("webEngineView")->title());
        this->setTabIcon(currentIndex, this->findChild<QWebEngineView*>("webEngineView")->icon());
        this->show();
    }
}




