#include "window_bubblesort.h"
#include "ui_window_bubblesort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

QString bs_adress_f, bs_adress_s;
bool bs_admin_file;

Window_BubbleSort::Window_BubbleSort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_BubbleSort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    bs_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\bubblesort.gif");
    ui->label_2->setMovie(bs_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    bs_movie->start();
}

Window_BubbleSort::~Window_BubbleSort()
{
    delete ui;
}

void Window_BubbleSort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        bs_adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText("Файл выбран");
        bs_admin_file = true;
    }

    else if(ok && choose){
        get_adress(bs_adress_f);
        if(!bs_adress_f.isEmpty()){

            if(is_empty_file(bs_adress_f)){
                QDesktopServices::openUrl(QUrl(bs_adress_f));
            }

            ui->pushButton_1->setText("Файл выбран");
            bs_admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }
}


void Window_BubbleSort::on_pushButton_2_clicked()
{
    get_adress(bs_adress_s);
    if(!bs_adress_s.isEmpty()){
        ui->pushButton_2->setText("Файл выбран");
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_BubbleSort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!bs_adress_s.isEmpty() && !bs_adress_f.isEmpty()){my_sorts(2,bs_adress_f,bs_adress_s, bs_admin_file);}
    else if(!bs_adress_s.isEmpty() && bs_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода");
        box.exec();
    }

    else if(bs_adress_s.isEmpty() && !bs_adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла");
        box.exec();
    }
}



