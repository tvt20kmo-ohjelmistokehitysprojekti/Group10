#include "log.h"
#include "ui_log.h"
#include "menu.h"
#include <QNetworkAccessManager>
#include <QtNetwork>

log::log(const QString &id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::log)
{
    ui->setupUi(this);
    idcard = id;

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
    request.setUrl(QUrl("http://www.students.oamk.fi/~c9karo00/Group10/RestApi/index.php/api/Action/?id="+id));

    QString concatenated = "admin:1234";
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    QNetworkReply *reply = manager->get(request);
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    answer.remove("\"");
    answer.replace("}", "\n");
    answer.replace("{", "\t");
    ui->label_log->setText(answer);
}

log::~log()
{
    delete ui;
}

void log::on_btn_back_clicked()
{  
    menu *m = new menu(idcard);
    this->close();
    m->show();
}
