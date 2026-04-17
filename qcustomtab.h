#ifndef QCUSTOMTAB_H
#define QCUSTOMTAB_H

#include <QWidget>
#include <qcustompushbutton.h>
#include <qtabwidget.h>
#include <qwebengineview.h>



class QCustomTab : public QWidget
{
    Q_OBJECT

protected:
    int index = -1;
    QTabWidget* container;
public:
    explicit QCustomTab(QWidget *parent = nullptr);


    QObject * getChildWidget(QString widgetName);
    void  on_webEngineView_loadStarted();


    void  webEngineView_setIconAndTitle();

    void setIndex(int index);
    void setContainer(QTabWidget* container);
    QTabWidget* getContainer();

    void webEngineView_setIcon(QIcon icon);

    void  webEngineView_setTitle(const QString &title);


    //Qui mettiamo slot e signals relativi al singolo tab widget
public slots:
    void onButtonClicked();    // Declaring a slot

};



#endif // QCUSTOMTAB_H
