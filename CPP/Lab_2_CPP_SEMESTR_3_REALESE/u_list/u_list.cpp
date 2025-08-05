#include "u_list.h"
#include "ui_u_list.h"

u_list::u_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::u_list)
{
    ui->setupUi(this);
}

u_list::~u_list()
{
    delete ui;
}
