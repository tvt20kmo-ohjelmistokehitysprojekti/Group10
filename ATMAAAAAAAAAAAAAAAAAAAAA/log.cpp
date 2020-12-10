#include "log.h"
#include "ui_log.h"

log::log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::log)
{
    ui->setupUi(this);
}

log::~log()
{
    delete ui;
}
