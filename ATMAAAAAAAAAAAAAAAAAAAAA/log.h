#ifndef LOG_H
#define LOG_H

#include <QNetworkAccessManager>
#include <QWidget>

namespace Ui {
class log;
}

class log : public QWidget
{
    Q_OBJECT

public:
    explicit log(const QString &id, QWidget *parent = nullptr);
    ~log();

private:
    Ui::log *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QString answer;
};

#endif // LOG_H
