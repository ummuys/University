#ifndef U_STACK_INFO_H
#define U_STACK_INFO_H

#include <QDialog>

namespace Ui {
class u_stack_info;
}

class u_stack_info : public QDialog
{
    Q_OBJECT

public:
    explicit u_stack_info(QWidget *parent = nullptr);
    ~u_stack_info();

private slots:
    void on_pushButton_clicked();

private:
    Ui::u_stack_info *ui;
};

#endif // U_STACK_INFO_H
