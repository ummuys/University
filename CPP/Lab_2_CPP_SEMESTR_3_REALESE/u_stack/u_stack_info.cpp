#include "u_stack/u_stack_info.h"
#include "ui_u_stack_info.h"
#include <QPixmap>
u_stack_info::u_stack_info(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::u_stack_info)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter);
}

u_stack_info::~u_stack_info()
{
    delete ui;
}

void u_stack_info::on_pushButton_clicked()
{

}

