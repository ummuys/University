#include "window_heapsort.h"
#include "ui_window_heapsort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

Window_HeapSort::Window_HeapSort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_HeapSort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    hs_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\heapsort.gif");
    ui->label_2->setMovie(hs_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    hs_movie->start();
}

Window_HeapSort::~Window_HeapSort()
{
    delete ui;
}

QString hs_adress_f, hs_adress_s;
bool hs_admin_file;


void Window_HeapSort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        hs_adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText("Файл выбран");
        hs_admin_file = true;
    }

    else if(ok && choose){
        get_adress(hs_adress_f);
        if(!hs_adress_f.isEmpty()){

            if(is_empty_file(hs_adress_f)){
                QDesktopServices::openUrl(QUrl(hs_adress_f));
            }

            ui->pushButton_1->setText("Файл выбран");
            hs_admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }
}


void Window_HeapSort::on_pushButton_2_clicked()
{
    get_adress(hs_adress_s);
    if(!hs_adress_s.isEmpty()){
        ui->pushButton_2->setText("Файл выбран");
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_HeapSort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!hs_adress_s.isEmpty() && !hs_adress_f.isEmpty()){my_sorts(6,hs_adress_f,hs_adress_s, hs_admin_file);}
    else if(!hs_adress_s.isEmpty() && hs_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода");
        box.exec();
    }

    else if(hs_adress_s.isEmpty() && !hs_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла");
        box.exec();
    }
}
