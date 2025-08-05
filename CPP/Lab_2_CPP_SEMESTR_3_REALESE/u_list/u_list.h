#ifndef U_LIST_H
#define U_LIST_H

#include <QDialog>

namespace Ui {
class u_list;
}

class u_list : public QDialog
{
    Q_OBJECT

public:
    explicit u_list(QWidget *parent = nullptr);
    ~u_list();

private:
    Ui::u_list *ui;
};

#endif // U_LIST_H
