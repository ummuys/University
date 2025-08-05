#ifndef WINDOW_HEAPSORT_H
#define WINDOW_HEAPSORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>

namespace Ui {
class Window_HeapSort;
}

class Window_HeapSort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_HeapSort(QWidget *parent = nullptr);
    ~Window_HeapSort();
    QMovie * hs_movie;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_HeapSort *ui;
};

#endif // WINDOW_HEAPSORT_H
