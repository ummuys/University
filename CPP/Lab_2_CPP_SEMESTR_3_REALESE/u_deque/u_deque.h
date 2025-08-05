#ifndef U_DEQUE_H
#define U_DEQUE_H

#include <QDialog>
#include <QDockWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QString>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include "u_deque_conteiner.h"

namespace Ui {
class u_deque;
}

class u_deque : public QDialog
{
    Q_OBJECT

public:
    explicit u_deque(QWidget *parent = nullptr);
    bool is_added(QGraphicsRectItem * rect);
    void off_buttons();
    void turn_back_buttons();
    void more_colorfull_rects(QGraphicsRectItem* rect);
    ~u_deque();

protected slots:
    void push_back_animation();
    void push_front_animation();
    void pop_back_animation();
    void pop_front_animation();
    void move_all_left();
    void move_all_right();
    void update_deque();
    void change_elems(u_deque_conteiner<QGraphicsRectItem*>& r_tmp, u_deque_conteiner<QGraphicsTextItem*>& t_tmp, int i);

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::u_deque *ui;
    QGraphicsScene * scene;
    QTimer * timer;
    QPen pen_rect;
    QPainter * painter;

    u_deque_conteiner<QGraphicsRectItem*> r_conteiner;
    u_deque_conteiner<QGraphicsTextItem*> t_conteiner;

    const int max_len = 5;
    int counter_elems = 0;
    int counter_x_move = 0;
    bool end_move = false;

};

#endif // U_DEQUE_H
