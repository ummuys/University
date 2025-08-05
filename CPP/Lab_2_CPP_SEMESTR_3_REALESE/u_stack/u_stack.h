#ifndef U_STACK_H
#define U_STACK_H

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
#include <QEnterEvent>
#include "u_stack_conteiner.h"


namespace Ui {
class u_stack;
}

class u_stack : public QDockWidget
{
    Q_OBJECT

public:
    explicit u_stack(QWidget *parent = nullptr);
    void off_buttons();
    void turn_back_buttons();
    void more_colorfull_rects(QGraphicsRectItem*rect);
    ~u_stack();


protected slots:
    void push_animation();
    void pop_animation();
    void update_stack();
    void change_elems(u_stack_conteiner<QGraphicsRectItem*>& r_tmp, u_stack_conteiner<QGraphicsTextItem*>& t_tmp, int i);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *event) override {

        if (event->spontaneous()) {
            r_conteiner.clear();
            t_conteiner.clear();
            delete scene;
            delete timer;
            delete painter;

        } else {
            QWidget::closeEvent(event);
        }
    }

private:
    Ui::u_stack *ui;
    QGraphicsScene * scene;
    QTimer * timer;

    u_stack_conteiner<QGraphicsRectItem*> r_conteiner;
    u_stack_conteiner<QGraphicsTextItem*> t_conteiner;

    QPen pen_rect;
    QPainter * painter;

    const int max_len = 5;
};

#endif // U_STACK_H
