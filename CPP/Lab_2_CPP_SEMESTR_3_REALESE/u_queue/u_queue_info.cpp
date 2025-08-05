#include "u_queue_info.h"
#include "ui_u_queue_info.h"
#include <QPixmap>

u_queue_info::u_queue_info(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::u_queue_info)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignHCenter);
}

u_queue_info::~u_queue_info()
{
    delete ui;
}
