#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Querymodel = new QSqlQueryModel(this);
    ui->pb_request->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_act_addData_triggered()
{
    settingBD = new setBD(this);
    settingBD->show();
}

void MainWindow::on_act_connect_triggered()
{
    if (ui->lb_statusConnect->text() == "Подключено")
    {
        mybd.close();
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->act_connect->setText("Подключиться");
        ui->pb_request->setEnabled(false);
    }
    else
    {
        QString host = settingBD->get_bd_host();
        QString name = settingBD->get_bd_name();
        QString username = settingBD->get_bd_username();
        QString password = settingBD->get_bd_password();
        int port = settingBD->get_bd_port();
        connectToDatabase (host, name, username, password, port);
    }
}

void MainWindow::connectToDatabase (QString &host, QString &name, QString &username, QString &password, int &port)
{
    mybd = QSqlDatabase::addDatabase("QPSQL");
    mybd.setHostName(host);
    mybd.setDatabaseName(name);
    mybd.setUserName(username);
    mybd.setPassword(password);
    mybd.setPort(port);
    if(mybd.open())
    {
        ui->lb_statusConnect->setText("Подключено");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->act_connect->setText("Отключиться");
        ui->pb_request->setEnabled(true);

        Tablemodel = new QSqlTableModel(this, mybd);
        Tablemodel->setTable("film");
        Tablemodel->select();

    }
    else
    {
        ui->lb_statusConnect->setText("Ошибка");
        ui->lb_statusConnect->setStyleSheet("color:red");
    }
}

void MainWindow::on_pb_request_clicked()
{
    QStringList categoryNames = {"", "Comedy", "Horror"};
    int index = ui->cb_category->currentIndex();
//---------------------------------------
    if (index == 0){
    ui->tb_result->setModel(Tablemodel);
//-------------------------------------
    }
    else
    {
        QString query = QString("SELECT title, description "
                                "FROM film f "
                                "JOIN film_category fc ON f.film_id = fc.film_id "
                                "JOIN category c ON c.category_id = fc.category_id "
                                "WHERE c.name = '%1';")
                        .arg(categoryNames.at(index));
    Querymodel->setQuery(query);

    ui->tb_result->setModel(Querymodel);
    }
}

void MainWindow::on_pb_clear_clicked()
{
    ui->tb_result->setModel(nullptr);
}
