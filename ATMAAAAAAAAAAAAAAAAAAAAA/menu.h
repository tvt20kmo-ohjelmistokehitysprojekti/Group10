#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QNetworkAccessManager>


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

    void on_btn_40_clicked();

    void on_btn_50_clicked();

    void on_btn_100_clicked();

    void on_btn_chooseSum_clicked();

    void on_btn_transactionQuery_clicked();

    void balanceQuery();

private:
    Ui::menu *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QString id, amount, answer;



};

#endif // MENU_H
