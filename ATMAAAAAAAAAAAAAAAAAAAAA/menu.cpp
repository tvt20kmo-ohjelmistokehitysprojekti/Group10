#include "menu.h"
#include "ui_menu.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QNetworkAccessManager>

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            QString answer = reply->readAll();

             ui->label_balance->setText(answer+ " €");

            qDebug() << answer;
        }
    );

}

menu::~menu()
{
    delete ui;
}

void menu::on_refresh_clicked()
{
    QString concatenated = "admin:1234";
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;

    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/Balance/?id=1"));

    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    manager->get(request);


}

void menu::on_btn_20_clicked()
{

}
