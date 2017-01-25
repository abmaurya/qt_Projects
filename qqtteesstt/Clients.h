#ifndef CLIENT_H
#define CLIENT_H

#include <QHostAddress>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#define host QHostAddress::LocalHost

class Clients: public QObject
{
    Q_OBJECT

    int timeout;
public:
    bool connected;
    Clients();
    ~Clients();
    QTcpSocket tcpobj;

public slots:
    void connecting();
    int disconnecting();
};

#endif // CLIENT_H

