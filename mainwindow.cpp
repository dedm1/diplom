#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
QString fileName;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QDoubleValidator *validator = new  QDoubleValidator(this);
    ui->Efile->setValidator(validator);
    ui->Egap->setValidator(validator);
    ui->Evs1->setValidator(validator);
    ui->Evs2->setValidator(validator);
    ui->Ehscale->setValidator(validator);
    ui->Edelay->setValidator(validator);

    ui->DC1->setEnabled(false);
    ui->AC1->setEnabled(false);
    ui->Evs1->setEnabled(false);

    ui->DC2->setEnabled(false);
    ui->AC2->setEnabled(false);
    ui->Evs2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void writes(double data)
{
    QFile file("/home/dedm/fuck/дипломная /qt /calc1/1.txt");
    if(file.open(QIODevice::WriteOnly))
       {
        QTextStream stream(&file);
        stream << data << endl;
        //  file.write(data);
       }
       file.close();
}
void writen(double data)
{
    fileName=fileName+"/1.txt";
    QFile file("/home/dedm/fuck/дипломная /qt /calc1/1.txt");
    if(file.open(QIODevice::Append))
       {
        QTextStream stream(&file);
        stream << data << endl;
        //  file.write(data);
       }
       file.close();
}



void MainWindow::on_pushButton_clicked()
{
    int file1 =0;
    double gap1 = 1;
    double delay1 = 0;
    double hscale1=1;
    double vs1 =1;
    double vs2 =2;

    QString x= ui->Efile->text();
      file1 = x.toInt();
    QString x1 = ui->Egap->text();
      gap1 = x1.toDouble();
     QString x2 = ui->Edelay->text();
       delay1 = x2.toDouble();
      QString x3 = ui->Ehscale->text();
        hscale1 = x3.toDouble();

    //ui->resul->setText(QString::number(hscale1));
        //ui->statusBar->showMessage("false2");

   int ACDC1=0;
    if (ui->checkBox->isChecked())
    {
        if (ui->AC1->isChecked())
        {
             ACDC1 = 1;
        }
        if (ui->DC1->isChecked())
        {
            ACDC1 = 2;
        }
        QString x = ui->Evs1->text();
          vs1 = x.toDouble();
    }
    else
    {
    ACDC1=0;
    }

    int ACDC2=0;
    if( ui->checkBox_2->isChecked())
    {
        if (ui->AC2->isChecked())
        {
             ACDC2 = 1;
        }
        if (ui->DC2->isChecked())
        {
                ACDC2 = 2;
        }
        QString x = ui->Evs2->text();
          vs2 = x.toDouble();
    }
    else
    {
      ACDC2 = 0;
    }

    if (file1!=0)
    {
        writes(file1);
        writen(gap1);
        writen(delay1);
        writen(hscale1);
        if (ACDC1!=0)
        {
            writen(1234);//момет странный надо подумать
            writen(vs1);
        }
        if (ACDC2!=0)
        {
            writen(834);
            writen(vs2);
        }

         ui->result->setText("Записалаось");
    }
    else {
              ui->result->setText("Введите File number");
    }
}


void MainWindow::on_checkBox_stateChanged(int state)
{
    if(Qt::Unchecked == state)
    {
        ui->DC1->setEnabled(false);
        ui->AC1->setEnabled(false);
        ui->Evs1->setEnabled(false);
    }
    else {
        ui->DC1->setEnabled(true);
        ui->AC1->setEnabled(true);
        ui->Evs1->setEnabled(true);
    }
}

void MainWindow::on_checkBox_2_stateChanged(int state1)
{
    if(Qt::Unchecked == state1)
    {
        ui->DC2->setEnabled(false);
        ui->AC2->setEnabled(false);
        ui->Evs2->setEnabled(false);
    }
    else {
        ui->DC2->setEnabled(true);
        ui->AC2->setEnabled(true);
        ui->Evs2->setEnabled(true);
    }
}

void MainWindow::on_choise_triggered()
{
    QString fileName = QFileDialog::getExistingDirectory(this, tr("сюда"), "");
           // fileName=fileName+"/1.txt"; не работает
         ui->label_6->setText(fileName);
}
