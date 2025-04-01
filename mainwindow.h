#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setbd.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_act_addData_triggered();
    void on_act_connect_triggered();
    void connectToDatabase (QString &host, QString &name, QString &username, QString &password, int &port);
    void on_pb_request_clicked();
    void on_pb_clear_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mybd;
    setBD *settingBD;
    QSqlQueryModel *Querymodel;
    QSqlTableModel *Tablemodel;


};
#endif // MAINWINDOW_H
