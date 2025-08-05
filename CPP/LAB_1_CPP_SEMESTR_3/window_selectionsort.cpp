#include "window_selectionsort.h"
#include "ui_window_selectionsort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

QString ss_adress_f, ss_adress_s;
bool ss_admin_file;

Window_SelectionSort::Window_SelectionSort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_SelectionSort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    ss_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\selectionsort.gif");
    ui->label_2->setMovie(ss_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    ss_movie->start();
}

Window_SelectionSort::~Window_SelectionSort()
{
    delete ui;
}


void Window_SelectionSort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        ss_adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText("Файл выбран");
        ss_admin_file = true;
    }

    else if(ok && choose){
        get_adress(ss_adress_f);
        if(!ss_adress_f.isEmpty()){

            if(is_empty_file(ss_adress_f)){
                QDesktopServices::openUrl(QUrl(ss_adress_f));
            }

            ui->pushButton_1->setText("Файл выбран");
            ss_admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }

}


void Window_SelectionSort::on_pushButton_2_clicked()
{
    get_adress(ss_adress_s);
    if(!ss_adress_s.isEmpty()){
        ui->pushButton_2->setText("Файл выбран");
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_SelectionSort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!ss_adress_s.isEmpty() && !ss_adress_f.isEmpty()){my_sorts(1,ss_adress_f,ss_adress_s, ss_admin_file);}
    else if(!ss_adress_s.isEmpty() && ss_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода");
        box.exec();
    }

    else if(ss_adress_s.isEmpty() && !ss_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла");
        box.exec();
    }
}
