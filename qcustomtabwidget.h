#ifndef QCUSTOMTABWIDGET_H
#define QCUSTOMTABWIDGET_H

#include <QWidget>
#include <qcustompushbutton.h>
#include <qtabwidget.h>

class QCustomTabWidget : public QTabWidget
{
    Q_OBJECT

protected:
    int index = -1;

public:
    explicit QCustomTabWidget(QTabWidget *parent = nullptr);


public:  QObject * getChildWidget(QString widgetName);
public: void  on_webEngineView_loadStarted();
public: void  on_webEngineView_loadFinished(bool arg1);
public: void     on_webEngineView_changeIcon(QIcon icon);
public: void     on_webEngineView_changeTitle(QString title);
public:    void  webEngineView_setIconAndTitle();

void setIndex(int index);

    //Qui mettiamo slot e signals relativi al singolo tab widget
 public slots:

    void onButtonClicked();    // Declaring a slot


};



#endif // QCUSTOMTABWIDGET_H
