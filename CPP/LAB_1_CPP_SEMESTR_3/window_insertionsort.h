#ifndef WINDOW_INSERTIONSORT_H
#define WINDOW_INSERTIONSORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>

namespace Ui {
class Window_InsertionSort;
}

class Window_InsertionSort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_InsertionSort(QWidget *parent = nullptr);
    ~Window_InsertionSort();
    QMovie * ins_movie;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_InsertionSort *ui;


};

#endif // WINDOW_INSERTIONSORT_H
