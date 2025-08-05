#ifndef U_QUEUE_H
#define U_QUEUE_H

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
#include "u_queue_conteiner.h"


namespace Ui {
class u_queue;
}

class u_queue : public QDialog
{
    Q_OBJECT

public:
    explicit u_queue(QWidget *parent = nullptr);
    bool is_added(QGraphicsRectItem * rect);
    void off_buttons();
    void turn_back_buttons();
    void more_colorfull_rects(QGraphicsRectItem*rect);
    ~u_queue();

protected slots:
    void push_animation();
    void pop_animation();
    void move_all_left();
    void update_queue();
    void change_elems(u_queue_conteiner<QGraphicsRectItem*>& r_tmp, u_queue_conteiner<QGraphicsTextItem*>& t_tmp, int i);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::u_queue *ui;
    QGraphicsScene * scene;
    QTimer * timer;
    QTimer * timer_to_move;

    u_queue_conteiner<QGraphicsRectItem*> r_conteiner;
    u_queue_conteiner<QGraphicsTextItem*> t_conteiner;

    QPen pen_rect;
    QPainter * painter;

    const int max_len = 5;
    int counter_elems = 0;
    int counter_x_move = 0;
    bool end_move = false;
};

#endif // U_QUEUE_H
