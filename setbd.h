#ifndef SETBD_H
#define SETBD_H

#include <QDialog>

namespace Ui {
class setBD;
}

class setBD : public QDialog
{
    Q_OBJECT

public:
    explicit setBD(QWidget *parent = nullptr);
    ~setBD();

    QString get_bd_host() const {return bd_host;}
    QString get_bd_name() const {return bd_name;}
    QString get_bd_username() const {return bd_username;}
    QString get_bd_password() const {return bd_password;}
    int get_bd_port() const {return bd_port;}

private slots:
    void on_buttonBox_accepted();

private:
    Ui::setBD *ui;

    QString bd_host;
    QString bd_name;
    QString bd_username;
    QString bd_password;
    int bd_port;
};

#endif // SETBD_H
