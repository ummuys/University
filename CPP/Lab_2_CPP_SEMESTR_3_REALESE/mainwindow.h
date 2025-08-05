#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "u_stack/u_stack.h"
#include "u_stack/u_stack_info.h"

#include "u_queue/u_queue.h"
#include "u_queue/u_queue_info.h"

#include "u_deque/u_deque.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

    u_stack u_stack;
    u_stack_info u_stack_info;


    u_queue u_queue;
    u_queue_info u_queue_info;


    u_deque u_deque;

};
#endif // MAINWINDOW_H
