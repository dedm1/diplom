#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDebug>
QString fileName;
QString fileName1;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QDoubleValidator *validator = new  QDoubleValidator(this);
     process = new QProcess(this);
    ui->Efile->setValidator(validator);
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
   // QFile file("/home/dedm/fuck/дипломная/qt/calc1/1.txt");
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly))
       {
        QTextStream stream(&file);
        stream << data  ;
        stream << "     #FILE NUM" << endl; ;
        //  file.write(data);
       }
       file.close();
}
void writen(double data ,int flag)
{
   // fileName="/home/dedm/fuck/дипломная/qt/calc1/1.txt";
    QFile file(fileName);
    if(file.open(QIODevice::Append))
    {
    if (flag==1)
    {
        QTextStream stream(&file);
        stream << data  ;
        stream << "     #DELAY(s)" << endl;

    }

    if (flag == 2)
    {
        if(data == 1)
        {
        QTextStream stream(&file);
        stream << "CH1,2"  ;
        stream << "     #CHANNELS" << endl;
        }

        if(data == 2)
        {
        QTextStream stream(&file);
        stream << "CH1"  ;
        stream << "     #CHANNELS" << endl;
        }

        if(data == 3)
        {
        QTextStream stream(&file);
        stream << "CH2"  ;
        stream << "     #CHANNELS" << endl;
        }

        if(data == 4)
        {
        QTextStream stream(&file);
        stream << "CH"  ;
        stream << "     #CHANNELS" << endl;
        }
    }


    if (flag==3)
    {
        QTextStream stream(&file);
        stream << data  ;
        stream << "     #HSCALE(s)" << endl;
    }
    if (flag==0)
    {
    if(file.open(QIODevice::Append))
       {
        QTextStream stream(&file);
        stream << data << endl;
       }
    }
    file.close();
    }
}
void writevs(double data ,double data1, int acdc1,int acdc2)
{
    QFile file(fileName);
    if(file.open(QIODevice::Append))
    {
     if(acdc1==0 && acdc2==0)
     {   QTextStream stream(&file);
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #ACVSCALES(V)" << endl;
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==1 && acdc2==0)
     {
         QTextStream stream(&file);
         stream << data  ;stream << ","  ;stream << "0";
         stream << "     #ACVSCALES(V)" << endl;
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==2 && acdc2==0)
     {
         QTextStream stream(&file);
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #ACVSCALES(V)" << endl;
         stream << data  ;stream << ","  ;stream << "0";
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==0 && acdc2==1)
     {
         QTextStream stream(&file);
         stream << "0"  ;stream << ","  ;stream << data1;
         stream << "     #ACVSCALES(V)" << endl;
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==0 && acdc2==2)
     {
         QTextStream stream(&file);
         stream << data  ;stream << ","  ;stream << "0";
         stream << "     #ACVSCALES(V)" << endl;
         stream << "0"  ;stream << ","  ;stream << data1;
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==1 && acdc2==1)
     {
         QTextStream stream(&file);
         stream << data  ;stream << ","  ;stream << data1;
         stream << "     #ACVSCALES(V)" << endl;
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==1 &&  acdc2==2)
     {
         QTextStream stream(&file);
         stream << data  ;stream << ","  ;stream << "0";
         stream << "     #ACVSCALES(V)" << endl;
         stream <<"0"  ;stream << ","  ;stream << data1;
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==2 &&  acdc2==1)
     {
         QTextStream stream(&file);
         stream << "0"  ;stream << ","  ;stream << data1;
         stream << "     #ACVSCALES(V)" << endl;
         stream << data  ;stream << ","  ;stream << "0";
         stream << "     #DCVSCALES(V)" << endl;
     }
     if(acdc1==2 &&  acdc2==2)
     {
         QTextStream stream(&file);
         stream << "0"  ;stream << ","  ;stream << "0";
         stream << "     #ACVSCALES(V)" << endl;
         stream << data  ;stream << ","  ;stream << data1;
         stream << "     #DCVSCALES(V)" << endl;
     }
    }
     file.close();
}


void MainWindow::on_pushButton_clicked()
{
    int file1 =0;
    double delay1 = 0;
    double hscale1=1;
    double vs1 =1;
    double vs2 =2;

    QString x= ui->Efile->text();
      file1 = x.toInt();
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
        writen(delay1,1);
        if (ACDC1!=0 && ACDC2!=0)
        {
                 writen(1,2);
        }
        if (ACDC1!=0 && ACDC2==0 )
        {
                writen(2,2);
        }
        if (ACDC1==0 && ACDC2!=0)
        {
                writen(3,2);
        }
        if (ACDC1==0 && ACDC2==0)
        {
                writen(4,2);
        }

        writen(hscale1,3);
        writevs(vs1,vs2,ACDC1,ACDC2);



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
   fileName1 = QFileDialog::getExistingDirectory(this, tr("сюда"), "");
            fileName=fileName1+QString("/1.txt");
            //fileName="D:/QT/diplom/qt/calc1/1.txt";
        // ui->label_6->setText(fileName);
}


void MainWindow::on_actionenter_triggered()
{
 QString fcopy=fileName1+QString("/3.exe");
    if (QFile::exists(fcopy))
    {
        QFile::remove(fcopy);
    }
    QString currnt= QDir::currentPath() + QString("/3.exe");
    ui->label_6->setText(currnt);
   qDebug() << QFile::copy(currnt, fcopy);
     QProcess process ;
   process.execute(fcopy);
}
