#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Freqvalidator = new QDoubleValidator(0,20e6,4,NULL);
    ui->StartFreq->setValidator(Freqvalidator);
    ui->StopFreq->setValidator(Freqvalidator);
    timevalidator = new QDoubleValidator(0,20e6,4,NULL);
    ui->sweeptime->setValidator(timevalidator);

    funcgen = new FunctionGenerator();
    running = true;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete funcgen;
    delete Freqvalidator;

}


void MainWindow::connectbuttonclicked()
{
    funcgen->OpenInstrument();
}
void MainWindow::ch1buttonclicked()
{
    if(running)
    {
    funcgen->setoutput(0);

    ui->CH1->setText("CH1 (OFF)");
      running = false;
    }
    else
    {
        funcgen->setoutput(1);

        ui->CH1->setText("CH1 (ON)");
          running = true;
    }
}
void MainWindow::ch2buttonclicked()
{
    if(running)
    {
    funcgen->setch2output(0);

    ui->CH2->setText("CH2 (OFF)");
      running = false;
    }
    else
    {
        funcgen->setch2output(1);

        ui->CH2->setText("CH2 (ON)");
          running = true;
    }
}


void MainWindow::startbuttonclicked()
{
    if(running)
    {

    funcgen->SweepFunc(0);
    ui->Start->setText("Start");
      running = false;
    }
    else
    {

        funcgen->SweepFunc(1);
        ui->Start->setText("Stop");
          running = true;
    }

    QString timetext = ui->sweeptime->text();
    double time = timetext.toDouble();
    funcgen->setsweeptime(time);
    QString freqstarttext = ui->StartFreq->text();
    double freqstart = freqstarttext.toDouble();
    QString freqstoptext = ui->StopFreq->text();
     double freqstop = freqstoptext.toDouble();
    funcgen->setfreqstart(freqstart);
    funcgen->setfreqstop(freqstop);
}
void MainWindow::wavestartbuttonclicked()
{

    if (ui->radiosin->isChecked())
        funcgen->GenerateSin();
    if (ui->radiosquare->isChecked())
        funcgen->GenerateSquare();
    if (ui->radionoise->isChecked())
        funcgen->GenerateNoise();



    QString setfreqtext = ui->setfreq->text();
    double freq = setfreqtext.toDouble();
    funcgen->setfreq(freq);

    QString setphasetext = ui->setphase->text();
    double phase = setphasetext.toDouble();
    funcgen->setphase(phase);

    QString setvolttext = ui->setvolt->text();
    double volt = setvolttext.toDouble();
    funcgen->setvolt(volt);

    QString setoffsettext = ui->offset->text();
    double offset = setoffsettext.toDouble();
    funcgen->setoffset(offset);
     QString sintext = ui->radiosin->text();




}
void MainWindow::stopbuttonclicked()
{
    funcgen->setoutput(0);
    funcgen->SweepFunc(0);
}
