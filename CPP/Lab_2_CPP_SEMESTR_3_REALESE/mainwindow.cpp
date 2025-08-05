#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRect>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_6->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    u_stack.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    u_stack_info.show();
}



void MainWindow::on_pushButton_3_clicked()
{
    u_queue.show();
}


void MainWindow::on_pushButton_4_clicked()
{
    u_queue_info.show();
}


void MainWindow::on_pushButton_5_clicked()
{
    u_deque.show();
}

