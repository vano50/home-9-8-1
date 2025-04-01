#include "setbd.h"
#include "./ui_setbd.h"
#include "setbd.h"
#include <QDebug>


setBD::setBD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setBD)
{
    ui->setupUi(this);
}

void setBD::on_buttonBox_accepted()
{
    bd_host = ui->le_host->text();
    bd_name = ui->le_dbName->text();
    bd_username = ui->le_login->text();
    bd_password = ui->le_pass->text();
    bd_port = ui->spB_port->value();
}

setBD::~setBD()
{
    delete ui;
}
