#include "menu.h"
#include "ui_menu.h"
#include "log.h"
#include <QNetworkAccessManager>
#include <QtNetwork>


menu::menu(const QString &idcard, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    id = idcard;

    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            answer = reply->readAll();
        }
    );

    balanceQuery();
}

menu::~menu()
{
    delete ui;
}

void menu::on_btn_withdraw_clicked()
{

    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/withdraw"));
    basicAuth();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("idAccount", id);
    params.addQueryItem("amount", amount);

    QNetworkReply *reply = manager->post(request, params.query().toUtf8());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    balanceQuery();

    ui->lineEdit_otherSum->setText("");
    amount = "0";
}

void menu::basicAuth()
{
    QString concatenated = "admin:1234";
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
}


void menu::balanceQuery()
{
    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/Balance/?id="+id));
    basicAuth();
    QNetworkReply *reply = manager->get(request);
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    answer.remove("\n");
    answer.remove("\"");
    ui->label_balance->setText("Saldo: "+answer+"€");

    ui->btn_20->setStyleSheet("background-color: none;font-size: 16px;");
    ui->btn_40->setStyleSheet("background-color: none;font-size: 16px;");
    ui->btn_50->setStyleSheet("background-color: none;font-size: 16px;");
    ui->btn_100->setStyleSheet("background-color: none;font-size: 16px;");
}



void menu::on_btn_deposit_clicked()
{
    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/Deposit/"));
    basicAuth();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("idAccount", id);
    params.addQueryItem("amount", amount);

    QNetworkReply *reply = manager->put(request, params.query().toUtf8());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    balanceQuery();

    ui->lineEdit_otherSum->setText("");
    amount = "0";

}

void menu::on_lineEdit_otherSum_editingFinished()
{
    amount = ui->lineEdit_otherSum->text();
}

void menu::on_btn_send_clicked()
{
    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/Transfer/"));
    basicAuth();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("idAccount1", id);
    params.addQueryItem("idAccount2", ui->lineEdit_receiverId->text());
    params.addQueryItem("amount", amount);

    QNetworkReply *reply = manager->put(request, params.query().toUtf8());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    balanceQuery();

    ui->lineEdit_otherSum->setText("");
    amount = "0";
}

void menu::on_btn_transactionQuery_clicked()
{
    class::log *l = new class::log(id);
    l->show();
    this->close();
}

void menu::on_btn_20_clicked()
{
    amount = "20";
    ui->btn_20->setStyleSheet("QPushButton{ background-color: grey;font-size: 16px;}");
}
void menu::on_btn_40_clicked()
{
    amount = "40";
    ui->btn_40->setStyleSheet("QPushButton{ background-color: grey;font-size: 16px;}");
}

void menu::on_btn_50_clicked()
{
    amount = "50";
    ui->btn_50->setStyleSheet("QPushButton{ background-color: grey;font-size: 16px;}");
}

void menu::on_btn_100_clicked()
{
    amount = "100";
    ui->btn_100->setStyleSheet("QPushButton{ background-color: grey;font-size: 16px;}");
}
