#ifndef QCUSTOMPUSHBUTTON_H
#define QCUSTOMPUSHBUTTON_H

#include "qpushbutton.h"
#include <QWidget>

class QCustomPushButton : public QPushButton
{
    Q_OBJECT

public: QCustomPushButton(QWidget* parent){
        this->setParent(parent);
}
public:
    explicit QCustomPushButton(QPushButton *parent = nullptr);
signals:
    void buttonClicked(QCustomPushButton* sender);  // Declaring a signal

};

#endif // QCUSTOMPUSHBUTTON_H
