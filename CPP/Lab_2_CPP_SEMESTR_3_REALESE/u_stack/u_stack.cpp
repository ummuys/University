#include "u_stack/u_stack.h"
#include "ui_u_stack.h"
#include <QMessageBox>

u_stack::u_stack(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::u_stack)
{
    ui->setupUi(this);
    pen_rect.setWidth(2);
    timer = new QTimer(this);

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

    scene->addLine(gv_x + gv_width/2 - 100, gv_y + gv_height - 50, gv_x + gv_width/2 + 100, gv_y + gv_height - 50,pen_scene);
    scene->addLine(gv_x + gv_width/2 - 100, gv_y + gv_height - 50, gv_x + gv_width/2 - 100, gv_y + gv_height - 360,pen_scene);
    scene->addLine(gv_x + gv_width/2 + 100, gv_y + gv_height - 50, gv_x + gv_width/2 + 100, gv_y + gv_height - 360,pen_scene);

}

void u_stack::push_animation(){
    if(r_conteiner.size() - 1 == 0){
        if(r_conteiner.top()->y() <= ui->graphicsView->height() - 110){
            this->r_conteiner.top()->setPos(r_conteiner.top()->x(), r_conteiner.top()->y() + 1);
            this->t_conteiner.top()->setPos(t_conteiner.top()->x(), t_conteiner.top()->y() + 1);
        }
        else {
            turn_back_buttons();
            timer->disconnect();
        }
    }
    else{
        if(r_conteiner.top()->y() <= r_conteiner.d_top()->y() - 60){
            this->r_conteiner.top()->setPos(r_conteiner.top()->x(), r_conteiner.top()->y() + 1);
            this->t_conteiner.top()->setPos(this->t_conteiner.top()->x(), this->t_conteiner.top()->y() + 1);
        }
        else {
            turn_back_buttons();
            timer->disconnect();
            update_stack();
        }
    }
}

void u_stack::pop_animation(){
    if(r_conteiner.top()->y() >= -100){
        this->r_conteiner.top()->setPos(r_conteiner.top()->x(), r_conteiner.top()->y() - 1);
        this->t_conteiner.top()->setPos(this->t_conteiner.top()->x(), this->t_conteiner.top()->y() - 1);
    }
    else{
        scene->removeItem(r_conteiner.top());
        scene->removeItem(t_conteiner.top());
        r_conteiner.pop();
        t_conteiner.pop();
        turn_back_buttons();
        timer->disconnect();
        update_stack();
    }
}

u_stack::~u_stack() {
}


void u_stack::on_pushButton_3_clicked()
{
    if(r_conteiner.size() == max_len)return;
    int gv_x = ui->graphicsView->x();
    int gv_y = ui->graphicsView->y();
    int gv_height = ui->graphicsView->height();
    int gv_width = ui->graphicsView->width();

    off_buttons();

    QGraphicsRectItem * rect = new QGraphicsRectItem;
    rect->setRect(gv_x + 5,gv_y, 190, 50);
    rect->setPos(gv_width/2 - 100, -100);
    rect->setPen(pen_rect);
    more_colorfull_rects(rect);
    this->scene->addItem(rect);
    r_conteiner.push(rect);

    QGraphicsTextItem * txt = this->scene->addText(QString::number(r_conteiner.size()));
    txt->setPos(gv_x + r_conteiner.top()->x() + 75, gv_y + r_conteiner.top()->y() - 10);
    txt->setDefaultTextColor(Qt::black);
    txt->setFont(QFont("Trebuchet MS"));
    txt->setScale(2.5);
    t_conteiner.push(txt);


    connect(timer, &QTimer::timeout, this, &u_stack::push_animation);
    timer->start(5);
}


void u_stack::on_pushButton_4_clicked()
{
    if(!r_conteiner.size())return;
    off_buttons();
    connect(timer, &QTimer::timeout, this, &u_stack::pop_animation);
    timer->start(5);
}

void u_stack::update_stack(){
    u_stack_conteiner<QGraphicsRectItem*> r_tmp;
    u_stack_conteiner<QGraphicsTextItem*> t_tmp;
    for(size_t i = 0; i < r_conteiner.size(); i++){
        change_elems(r_tmp, t_tmp, i);
    }

    r_conteiner.clear_and_update(r_tmp.get_tail(), r_tmp.size());
    t_conteiner.clear_and_update(t_tmp.get_tail(), t_tmp.size());
}


void u_stack::change_elems(u_stack_conteiner<QGraphicsRectItem*>& r_tmp, u_stack_conteiner<QGraphicsTextItem*>& t_tmp, int i){
    int gv_x = ui->graphicsView->x();
    int gv_y = ui->graphicsView->y();

    QGraphicsRectItem * rect = new QGraphicsRectItem;
    rect->setRect(gv_x + 5,gv_y, 190, 50);
    rect->setPos(r_conteiner[r_conteiner.size() - i - 1]->x(), r_conteiner[r_conteiner.size() - i - 1]->y());
    rect->setPen(pen_rect);
    rect->setBrush(r_conteiner[r_conteiner.size() - i - 1]->brush());
    this->scene->removeItem(r_conteiner[r_conteiner.size() - i - 1]);
    this->scene->addItem(rect);
    r_tmp.push(rect);
    this->scene->removeItem(t_conteiner[r_conteiner.size() - i - 1]);

    QGraphicsTextItem * txt = this->scene->addText(QString::number(r_conteiner.size() - r_tmp.size() + 1));
    txt->setPos(gv_x + r_tmp[r_tmp.size() - i - 1]->x() + 75, gv_y + r_tmp[r_tmp.size() - i - 1]->y() - 10);
    txt->setDefaultTextColor(Qt::black);
    txt->setFont(QFont("Trebuchet MS"));
    txt->setScale(2.5);
    t_tmp.push(txt);
}


void u_stack::on_pushButton_2_clicked()
{
    QMessageBox box;
    if(r_conteiner.size()){
        box.setText("Значение головного элемента -> " + QString::number(r_conteiner.size()));
    }
    else{
        box.setText("Стэк пуст!");
    }
    box.exec();
}


void u_stack::on_pushButton_clicked()
{
    QMessageBox box;
    if(r_conteiner.size()){
        if(r_conteiner.size() == 1){
            box.setText("В стеке " + QString::number(r_conteiner.size()) + " элемент");
        }
        else{
            box.setText("В стеке " + QString::number(r_conteiner.size()) + " элемента");
        }
    }
    else{
        box.setText("Стэк пуст!");
    }
    box.exec();
}

void u_stack::off_buttons(){
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

void u_stack::turn_back_buttons(){
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


void u_stack::more_colorfull_rects(QGraphicsRectItem* rect){
    int n1 = rand() % 255;
    int n2 = rand() % 255;
    int n3 = rand() % 255;
    rect->setBrush(QColor(n1,n2,n3));
}


