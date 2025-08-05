#include "window_mergesort.h"
#include "ui_window_mergesort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

QString ms_adress_f, ms_adress_s;
bool ms_admin_file;

Window_MergeSort::Window_MergeSort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_MergeSort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    ms_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\mergesort.gif");
    ui->label_2->setMovie(ms_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    ms_movie->start();
}

Window_MergeSort::~Window_MergeSort()
{
    delete ui;
}

void Window_MergeSort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        ms_adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText("Файл выбран");
        ms_admin_file = true;
    }

    else if(ok && choose){
        get_adress(ms_adress_f);
        if(!ms_adress_f.isEmpty()){

            if(is_empty_file(ms_adress_f)){
                QDesktopServices::openUrl(QUrl(ms_adress_f));
            }

            ui->pushButton_1->setText("Файл выбран");
            ms_admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }

}


void Window_MergeSort::on_pushButton_2_clicked()
{
    get_adress(ms_adress_s);
    if(!ms_adress_s.isEmpty()){
        ui->pushButton_2->setText("Файл выбран");
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_MergeSort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!ms_adress_s.isEmpty() && !ms_adress_f.isEmpty()){my_sorts(5,ms_adress_f,ms_adress_s, ms_admin_file);}
    else if(!ms_adress_s.isEmpty() && ms_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода");
        box.exec();
    }

    else if(ms_adress_s.isEmpty() && !ms_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла");
        box.exec();
    }
}
