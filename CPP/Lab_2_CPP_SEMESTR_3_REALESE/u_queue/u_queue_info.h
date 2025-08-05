#ifndef U_QUEUE_INFO_H
#define U_QUEUE_INFO_H

#include <QDialog>

namespace Ui {
class u_queue_info;
}

class u_queue_info : public QDialog
{
    Q_OBJECT

public:
    explicit u_queue_info(QWidget *parent = nullptr);
    ~u_queue_info();

private:
    Ui::u_queue_info *ui;
};

#endif // U_QUEUE_INFO_H
