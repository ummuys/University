#include "u_queue/u_queue.h"
#include "ui_u_queue.h"
#include <QMessageBox>
#include <QThread>

u_queue::u_queue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::u_queue)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);

    pen_rect.setWidth(2);
    timer = new QTimer();

    QPen pen_scene;
    pen_scene.setWidth(2);
    pen_scene.setColor(Qt::black);

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);

    int gv_x = ui->graphicsView->x();
    int gv_y = ui->graphicsView->y();
    int gv_height = ui->graphicsView->height();
    int gv_width = ui->graphicsView->width();


    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(gv_x, gv_y, gv_width, gv_height);
    ui->graphicsView->setScene(scene);

    scene->addLine(gv_x + 150, gv_y + gv_height/2 - 75, gv_x + 500, gv_y + gv_height/2 - 75, pen_scene);
    scene->addLine(gv_x + 150, gv_y + gv_height/2 + 75, gv_x + 500, gv_y + gv_height/2 + 75, pen_scene);
}

u_queue::~u_queue()
{
    delete ui;
}


void u_queue::off_buttons(){
    ui->pushButton_4->setStyleSheet("background-color: #00CED1");
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setStyleSheet("background-color: #00CED1");
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setStyleSheet("background-color: #00CED1");
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setStyleSheet("background-color: #00CED1");
    ui->pushButton->setEnabled(false);
    ui->label->setText("Выполняется действие, ожидайте . . . ");
}

void u_queue::turn_back_buttons(){
    ui->pushButton_4->setStyleSheet("background-color: #00FFFF");
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_3->setStyleSheet("background-color: #00FFFF");
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setStyleSheet("background-color: #00FFFF");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setStyleSheet("background-color: #00FFFF");
    ui->pushButton->setEnabled(true);
    ui->label->setText("Ожидается действие");
}


void u_queue::more_colorfull_rects(QGraphicsRectItem*rect){
    int n1 = rand() % 255;
    int n2 = rand() % 255;
    int n3 = rand() % 255;
    rect->setBrush(QColor(n1,n2,n3));
}

void u_queue::on_pushButton_3_clicked()
{
    if(r_conteiner.size() == max_len)return;
    int gv_x = ui->graphicsView->x();
    int gv_y = ui->graphicsView->y();
    int gv_height = ui->graphicsView->height();

    off_buttons();

    QGraphicsRectItem * rect = new QGraphicsRectItem;
    rect->setRect(gv_x, gv_y, 50, 140);
    rect->setPos(gv_x + 700, gv_y + gv_height/2 - 130);
    rect->setPen(pen_rect);
    more_colorfull_rects(rect);
    this->scene->addItem(rect);
    r_conteiner.push_back(rect);

    QGraphicsTextItem * txt = this->scene->addText(QString::number(r_conteiner.size()));
    txt->setPos(gv_x + r_conteiner[r_conteiner.size() - 1]->x() + 5, gv_y + r_conteiner[r_conteiner.size() - 1]->y() + 30);
    txt->setDefaultTextColor(Qt::black);
    txt->setFont(QFont("Trebuchet MS"));
    txt->setScale(2.5);
    t_conteiner.push_back(txt);

    connect(timer, &QTimer::timeout, this, &u_queue::push_animation);
    timer->start(5);
}

void u_queue::push_animation(){
    if(r_conteiner.size() - 1 == 0){
        if(r_conteiner[r_conteiner.size() - 1]->x() >= ui->graphicsView->x() + 140){
            r_conteiner[r_conteiner.size() - 1]->setPos(r_conteiner[r_conteiner.size() - 1]->x() - 1, r_conteiner[r_conteiner.size() - 1]->y());
            this->t_conteiner[t_conteiner.size() - 1]->setPos(this->t_conteiner[t_conteiner.size() - 1]->x() - 1, this->t_conteiner[t_conteiner.size() - 1]->y());
        }
        else {
            turn_back_buttons();
            timer->disconnect();
        }
    }
    else{
        if(r_conteiner[r_conteiner.size() - 1]->x() >= r_conteiner[r_conteiner.size() - 2]->x() + 60){
            this->r_conteiner[r_conteiner.size() - 1]->setPos(r_conteiner[r_conteiner.size() - 1]->x() - 1, r_conteiner[r_conteiner.size() - 1]->y());
            this->t_conteiner[t_conteiner.size() - 1]->setPos(this->t_conteiner[t_conteiner.size() - 1]->x() - 1, this->t_conteiner[t_conteiner.size() - 1]->y());
        }
        else {
            turn_back_buttons();
            timer->disconnect();
        }
    }
}

void u_queue::pop_animation(){
    if(r_conteiner.front()->x() >= -100){
        this->r_conteiner.front()->setPos(r_conteiner.front()->x() - 1, r_conteiner.front()->y());
        this->t_conteiner.front()->setPos(this->t_conteiner.front()->x() - 1, this->t_conteiner.front()->y());
    }
    else{
        scene->removeItem(r_conteiner.front());
        scene->removeItem(t_conteiner.front());
        r_conteiner.pop_front();
        t_conteiner.pop_front();
        timer->disconnect();
        connect(timer, &QTimer::timeout, this, &u_queue::move_all_left);
    }
}

void u_queue::move_all_left(){
    if(counter_elems < r_conteiner.size()){
        if(counter_x_move <= 60){
            r_conteiner[counter_elems]->setPos(r_conteiner[counter_elems]->x() - 1, r_conteiner[counter_elems]->y());
            this->t_conteiner[counter_elems]->setPos(this->t_conteiner[counter_elems]->x() - 1, this->t_conteiner[counter_elems]->y());
            counter_x_move++;
        }
        else{
            counter_elems++;
            counter_x_move = 0;
        }
    }
    else{
        turn_back_buttons();
        counter_elems = 0;
        counter_x_move = 0;
        timer->disconnect();
        update_queue();
    }
}

void u_queue::update_queue(){
    u_queue_conteiner<QGraphicsRectItem*> r_tmp;
    u_queue_conteiner<QGraphicsTextItem*> t_tmp;
    for(size_t i = 0; i < r_conteiner.size(); i++){
        change_elems(r_tmp, t_tmp, i);
    }

    r_conteiner.clear_and_update(r_tmp.get_head(), r_tmp.get_tail(), r_tmp.size());
    t_conteiner.clear_and_update(t_tmp.get_head(), t_tmp.get_tail(), t_tmp.size());
}

void u_queue::change_elems(u_queue_conteiner<QGraphicsRectItem*>& r_tmp, u_queue_conteiner<QGraphicsTextItem*>& t_tmp, int i){
    int gv_x = ui->graphicsView->x();
    int gv_y = ui->graphicsView->y();

    QGraphicsRectItem * rect = new QGraphicsRectItem;
    rect->setRect(gv_x, gv_y, 50, 140);
    rect->setPos(r_conteiner[i]->x(), r_conteiner[i]->y());
    rect->setPen(pen_rect);
    rect->setBrush(r_conteiner[i]->brush());
    this->scene->removeItem(r_conteiner[i]);
    this->scene->addItem(rect);
    r_tmp.push_back(rect);

    this->scene->removeItem(t_conteiner[i]);
    QGraphicsTextItem * txt = this->scene->addText(QString::number(r_tmp.size()));
    txt->setPos(gv_x + r_tmp[r_tmp.size() - 1]->x() + 5, gv_y + r_tmp[r_tmp.size() - 1]->y() + 30);
    txt->setDefaultTextColor(Qt::black);
    txt->setFont(QFont("Trebuchet MS"));
    txt->setScale(2.5);
    t_tmp.push_back(txt);
}

void u_queue::on_pushButton_4_clicked()
{
    if(!r_conteiner.size())return;
    off_buttons();
    connect(timer, &QTimer::timeout, this, &u_queue::pop_animation);
    timer->start(5);
}


void u_queue::on_pushButton_2_clicked()
{
    QMessageBox box;
    if(r_conteiner.size()){
        box.setText("Значение головного элемента -> " + QString::number(1));
    }
    else{
        box.setText("Очередь пуста!");
    }
    box.exec();
}


void u_queue::on_pushButton_clicked()
{
    QMessageBox box;
    if(r_conteiner.size()){
        box.setText("Значение хвостового элемента -> " + QString(t_conteiner[t_conteiner.size() - 1]->toPlainText()));
    }
    else{
        box.setText("Очередь пуста!");
    }
    box.exec();
}

