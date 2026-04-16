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

      void on_goButton_clicked();

     void on_webEngineView_loadFinished(bool arg1);
      void  webEngineView_setIcon(QIcon arg1);
      void  webEngineView_setTitle(const QString &title);

    void on_newTabButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
