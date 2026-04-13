#ifndef QCUSTOMTABWIDGET_H
#define QCUSTOMTABWIDGET_H

#include <QWidget>
#include <qcustompushbutton.h>
#include <qtabwidget.h>

class QCustomTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit QCustomTabWidget(QTabWidget *parent = nullptr);


public:  QObject * getChildWidget(QString widgetName);
public: void  on_webEngineView_loadStarted();
public:    void  on_webEngineView_loadFinished(bool arg1);

    //Qui mettiamo slot e signals relativi al singolo tab widget
 public slots:

    void onButtonClicked();    // Declaring a slot


};



#endif // QCUSTOMTABWIDGET_H
