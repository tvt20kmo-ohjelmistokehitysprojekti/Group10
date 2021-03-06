#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include <QNetworkAccessManager>
#include <QtNetwork>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }
            answer = reply->readAll();
            reply->deleteLater();
        }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnlogin_clicked()
{
    idcard = ui->lineEdit_id->text();
    pin = ui->lineEdit_pin->text();

    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/Login/check_login?idCard="+idcard+"&Password="+pin));

    QString concatenated = "admin:1234";
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    QNetworkReply *reply = manager->get(request);
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    if(idcard!=""){
        if(answer=="true"){
            menu *m = new menu(idcard);
            m->show();
            close();
        }
        else{
            ui->label_paska->setStyleSheet("color: red;");
            ui->label_paska->setText("Väärä id tai pin");
        }
    }
}
