#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QNetworkAccessManager>
#include "mainwindow.h"

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(const QString &idcard, QWidget *parent = nullptr);
    ~menu();



private slots:
    void on_refresh_clicked();

    void on_btn_20_clicked();

    void basicAuth();

    void on_btn_withdraw_clicked();

private:
    Ui::menu *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QString id, amount, answer;



};

#endif // MENU_H
