#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);


    void on_choise_triggered();

    void on_actionenter_triggered();

private:
    Ui::MainWindow *ui;
    QProcess *process;
};

#endif // MAINWINDOW_H
