#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void write(double data)
{
    std::ofstream out;          // поток для записи
       out.open("/home/dedm/fuck/дипломная /qt /calc1/1.txt"); // окрываем файл для записи
       if (out.is_open())
       {
           out << data << std::endl;
       }
       out.close();
}
void writen(double data)
{
    std::ofstream out;          // поток для записи
       out.open("/home/dedm/fuck/дипломная /qt /calc1/1.txt", std::ios::app); // окрываем файл для записи
       if (out.is_open())
       {
           out << data << std::endl;
       }
       out.close();
}

void MainWindow::on_pushButton_clicked()
{
// запретить в editline писать буквы
//пока не поставлена голочка запретить тыкать
// подумать как передовать значение с галочкой
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
    ui->res->setText(QString::number(ACDC1));
    }


    int ACDC2=0;
    if( ui->checkBox_2->isChecked())
    {
        if (ui->AC2->isChecked())
        {
             ACDC2 = 1;
            ui->res->setText(QString::number(ACDC2));
        }
        if (ui->DC2->isChecked())
        {
                ACDC2 = 2;
                ui->res->setText(QString::number(ACDC2));
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
        write(file1);
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




