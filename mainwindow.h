#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <FunctionGenerator.h>
#include <visainst.h>
#include <visa.h>
#include <QDoubleValidator>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    FunctionGenerator* funcgen;
    QDoubleValidator* Freqvalidator;
    QDoubleValidator* timevalidator;

    bool running;

public slots:
    void connectbuttonclicked();
    void startbuttonclicked();
    void stopbuttonclicked();
    void ch1buttonclicked();
    void wavestartbuttonclicked();
    void ch2buttonclicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
