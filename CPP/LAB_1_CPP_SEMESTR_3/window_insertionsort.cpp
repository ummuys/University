#include "window_insertionsort.h"
#include "ui_window_insertionsort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

QString ins_adress_f, ins_adress_s;
bool ins_admin_file;

Window_InsertionSort::Window_InsertionSort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_InsertionSort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    ins_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\insertionsort.gif");
    ui->label_2->setMovie(ins_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    ins_movie->start();
}

Window_InsertionSort::~Window_InsertionSort()
{
    delete ui;
}


void Window_InsertionSort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        ins_adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText("Файл выбран");
        ins_admin_file = true;
    }

    else if(ok && choose){
        get_adress(ins_adress_f);
        if(!ins_adress_f.isEmpty()){

            if(is_empty_file(ins_adress_f)){
                QDesktopServices::openUrl(QUrl(ins_adress_f));
            }

            ui->pushButton_1->setText("Файл выбран");
            ins_admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }

}


void Window_InsertionSort::on_pushButton_2_clicked()
{
    get_adress(ins_adress_s);
    if(!ins_adress_s.isEmpty()){
        ui->pushButton_2->setText("Файл выбран");
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_InsertionSort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!ins_adress_s.isEmpty() && !ins_adress_f.isEmpty()){my_sorts(3,ins_adress_f,ins_adress_s, ins_admin_file);}
    else if(!ins_adress_s.isEmpty() && ins_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода");
        box.exec();
    }

    else if(ins_adress_s.isEmpty() && !ins_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла");
        box.exec();
    }
}
