#ifndef WINDOW_MERGESORT_H
#define WINDOW_MERGESORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>

namespace Ui {
class Window_MergeSort;
}

class Window_MergeSort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_MergeSort(QWidget *parent = nullptr);
    ~Window_MergeSort();
    QMovie * ms_movie;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_MergeSort *ui;
};

#endif // WINDOW_MERGESORT_H
