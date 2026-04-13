#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_goButton0_clicked();
      void on_goButton_clicked();

    void on_urlEdit0_returnPressed();

    void on_urlEdit_returnPressed();

    void on_webEngineView0_loadStarted();

    void on_webEngineView0_loadFinished(bool arg1);
     void on_webEngineView_loadFinished(bool arg1);

    void on_newTabButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
