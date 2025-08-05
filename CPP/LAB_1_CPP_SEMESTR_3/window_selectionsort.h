#ifndef WINDOW_SELECTIONSORT_H
#define WINDOW_SELECTIONSORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>


namespace Ui {
class Window_SelectionSort;
}

class Window_SelectionSort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_SelectionSort(QWidget *parent = nullptr);
    ~Window_SelectionSort();
    QMovie * ss_movie;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_SelectionSort *ui;
};

#endif // WINDOW_SELECTIONSORT_H
