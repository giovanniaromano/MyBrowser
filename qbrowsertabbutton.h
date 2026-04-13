#ifndef QBROWSERTABBUTTON_H
#define QBROWSERTABBUTTON_H

#include "qpushbutton.h"
#include <QWidget>

class QBrowserTabButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QBrowserTabButton(QPushButton *parent = nullptr);


private slots:
    void onClicked();

signals:
};

#endif // QBROWSERTABBUTTON_H
