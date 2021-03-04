#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
int ACDC1=0 ;
int ACDC2=0 ;

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


void write(int data)
{
    std::ofstream out;          // поток для записи
       out.open("/home/dedm/fuck/дипломная /qt /calc/1.txt"); // окрываем файл для записи
       if (out.is_open())
       {
           out << data << std::endl;
       }
       out.close();
}
void writen(int data)
{
    std::ofstream out;          // поток для записи
       out.open("/home/dedm/fuck/дипломная /qt /calc/1.txt", std::ios::app); // окрываем файл для записи
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

    QString x= ui->Efile->text();
     int file1 = x.toInt();
    QString x1 = ui->Egap->text();
     int gap1 = x1.toInt();
     QString x2 = ui->Edelay->text();
      int delay1 = x2.toInt();
      QString x3 = ui->Ehscale->text();
       int hscale1 = x3.toInt();
        if (file1!=0)
        {
            write(file1);
            writen(gap1);
             ui->resul->setText("Записалаось");
        }
        else {
                  ui->resul->setText("Введите File number");
        }

    //ui->resul->setText(QString::number(hscale1));





}

void MainWindow::on_checkBox_clicked(bool checked)
{
    ACDC1=0;
    if( !checked )
    {
         ui->statusBar->showMessage("хее1");
        if (ui->AC1->isChecked())
        {
           // ui->statusBar->showMessage("жопа");
             ACDC1 = 1;
            ui->statusBar->showMessage("1", ACDC1);
        }
        if (ui->DC1->isChecked())
        {
           // ui->statusBar->showMessage("DC1");
                ACDC1 = 2;
                ui->statusBar->showMessage("1", ACDC1);
        }
        QString x = ui->Evs1->text();
         int vs1 = x.toInt();
    }
    else
    {
    ui->statusBar->showMessage("false");
    }
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    ACDC2=0;
    if( !checked )
    {
         ui->statusBar->showMessage("хее");
        if (ui->AC2->isChecked())
        {
           // ui->statusBar->showMessage("жоп");
             ACDC2 = 1;
            ui->statusBar->showMessage("2", ACDC2);
        }
        if (ui->DC2->isChecked())
        {
           // ui->statusBar->showMessage("DC2");
                ACDC2 = 2;
                ui->statusBar->showMessage("2", ACDC2);
        }
        QString x = ui->Evs2->text();
         int vs2 = x.toInt();
    }
    else
    {
    ui->statusBar->showMessage("false2");
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    ui->res->setText(QString::number(ACDC2));
}
