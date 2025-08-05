#include "window_quicksort.h"
#include "ui_window_quicksort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

QString qs_adress_f, qs_adress_s;
bool qs_admin_file;

Window_Quicksort::Window_Quicksort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_Quicksort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    qs_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\qsort.gif");
    ui->label_2->setMovie(qs_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    qs_movie->start();
}

Window_Quicksort::~Window_Quicksort()
{
    delete ui;
}

void Window_Quicksort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        qs_adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText("Файл выбран");
        qs_admin_file = true;
    }

    else if(ok && choose){
        get_adress(qs_adress_f);
        if(!qs_adress_f.isEmpty()){

            if(is_empty_file(qs_adress_f)){
                QDesktopServices::openUrl(QUrl(qs_adress_f));
            }

            ui->pushButton_1->setText("Файл выбран");
            qs_admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }

}


void Window_Quicksort::on_pushButton_2_clicked()
{
    get_adress(qs_adress_s);
    if(!qs_adress_s.isEmpty()){
        ui->pushButton_2->setText("Файл выбран");
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_Quicksort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!qs_adress_s.isEmpty() && !qs_adress_f.isEmpty()){my_sorts(4,qs_adress_f,qs_adress_s, qs_admin_file);}
    else if(!qs_adress_s.isEmpty() && qs_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода");
        box.exec();
    }

    else if(qs_adress_s.isEmpty() && !qs_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла");
        box.exec();
    }
}
