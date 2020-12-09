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
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_refresh_clicked();

    void on_btn_20_clicked();

private:
    Ui::menu *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
};

#endif // MENU_H
