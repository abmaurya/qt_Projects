#ifndef SERVING_H
#define SERVING_H
#include <QTcpServer>
#include <QHostAddress>
#include <QObject>
#include <QDebug>

#define host QHostAddress::LocalHost
#define NEVER_SERVED 0
#define SERVING 1
#define SERVER_CLOSED 2
class serving: public QObject
{
    Q_OBJECT

    QTcpServer serv_sock;
public:
    int status;
    serving();
    ~serving();

    void onNewConnection();

public slots:

    void closin();
    void serv();
};

#endif // SERVING_H
