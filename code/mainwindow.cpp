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
    ui->Egap->setValidator(validator);

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
    QFile mFile(fileName);
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly))
       {
        QTextStream stream(&file);
        stream << "####COMMON#### " << endl;
        stream << "FILE NUMBER     : " ;
        stream << data  << endl;
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
        if (flag==11)
        {
            QTextStream stream(&file);
            stream << "TIME GAP	: ";
            stream << data << endl ;

        }
    if (flag==1)
    {
        QTextStream stream(&file);
        stream << "DELAY		: ";
        stream << data << endl ;

    }

    if (flag == 2)
    {
        if(data == 1)
        {
        QTextStream stream(&file);
        stream << "####CH1####" << endl;
        stream << "ON" << endl;
        stream << "AC" << endl;
        }

        if(data == 2)
        {
            QTextStream stream(&file);
            stream << "####CH1####" << endl;
            stream << "ON" << endl;
            stream << "DC" << endl;
        }

        if(data == 3)
        {
        QTextStream stream(&file);
        stream << "####CH1####" << endl;
        stream << "OFF" << endl;
        stream << "AC" << endl;
        }

        if(data == 4)
        {
        QTextStream stream(&file);
        stream << "####CH2####" << endl;
        stream << "ON" << endl;
        stream << "AC" << endl;
        }
        if(data == 5)
        {
        QTextStream stream(&file);
        stream << "####CH2####" << endl;
        stream << "ON" << endl;
        stream << "DC" << endl;
        }
        if(data == 6)
        {
        QTextStream stream(&file);
        stream << "####CH1####" << endl;
        stream << "OFF" << endl;
        stream << "AC" << endl;
        }
    }


    if (flag==3)
    {
        QTextStream stream(&file);
        stream << "HSCALE		: " ;
        stream << data << endl ;
        stream << ""<< endl;
    }
    if (flag==4)
    {
        QTextStream stream(&file);
        stream << "VSCALE		: ";
        stream << data << endl ;
    }
    if (flag==5)
    {
        QTextStream stream(&file);
        stream << "VPOS		: " ;
        stream << data  << endl;
        stream << ""<< endl;
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


void MainWindow::on_pushButton_clicked()
{
    int file1 =0;
    double delay1 = 0;
    double hscale1=1;
    double vs1 =1;
    double vs2 =2;
    double gap1 =1;

    QString x= ui->Efile->text();
      file1 = x.toInt();
      QString x1 = ui->Egap->text();
     std::replace( x1.begin(), x1.end(), ',', '.' );
        gap1 = x1.toDouble();
     QString x2 = ui->Edelay->text();
     std::replace( x2.begin(), x2.end(), ',', '.' );
       delay1 = x2.toDouble();
      QString x3 = ui->Ehscale->text();
      std::replace( x3.begin(), x3.end(), ',', '.' );
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
        std::replace( x.begin(), x.end(), ',', '.' );
          vs2 = x.toDouble();
    }
    else
    {
      ACDC2 = 0;
    }

    if (file1!=0)
    {
        writes(file1);
        writen(gap1,11);
        writen(delay1,1);
         writen(hscale1,3);

         if (ACDC1 ==1)
         {
                  writen(1,2);
         }
         if (ACDC1 ==2)
         {
                  writen(2,2);
         }
         if (ACDC1 ==0)
         {
                  writen(3,2);
         }
         writen(vs1,4);
         writen(0,5);

         if (ACDC2 ==1)
         {
                  writen(4,2);
         }
         if (ACDC2 ==2)
         {
                  writen(5,2);
         }
         if (ACDC2 ==0)
         {
                  writen(6,2);
         }
         writen(vs2,4);
         writen(0,5);


         ui->result->setText("Записалось");
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
            fileName=fileName1+QString("/SET.txt");
            //fileName="D:/QT/diplom/qt/calc1/1.txt";
        // ui->label_6->setText(fileName);
}


void MainWindow::on_actionenter_triggered()
{
 QString fcopy=fileName1+QString("/3.exe");
    QString currnt= QDir::currentPath() + QString("/3.exe");
    ui->label_6->setText(fcopy);
    if (QFile::exists(fcopy))
    {
        if(fcopy != currnt)
        {
        QFile::remove(fcopy);
        }
    }
   qDebug() << QFile::copy(currnt, fcopy);
 \
   QByteArray ba = fcopy.toLocal8Bit();
   const char *pyte = ba.data();
   system(pyte);
}
