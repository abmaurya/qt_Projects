#include "Clients.h"


Clients::Clients(){
    timeout = 2000;
    connected = false;
}

Clients::~Clients(){
    //connected = NULL;
    tcpobj.deleteLater();
    //tcpobj.~QObject();
}

//Function to connect to server
void Clients::connecting(){

    //Checking if already connected to the given Server
    if(tcpobj.waitForConnected(timeout))
        qDebug()<<"Already Connected";
    else
    {
        //Connects to the given host on Port 1995
        tcpobj.connectToHost(host,1995);

        //Checking again if connected to the Server
        if(tcpobj.waitForConnected(timeout)){
            qDebug()<<"Connected";
            connected = true;
        }
        else qDebug()<<"Can't Connect";
    }
}

int Clients::disconnecting(){
    if(tcpobj.waitForConnected(2)){
        tcpobj.close();
        qDebug()<<"Client Disconnected";
        connected = false;
        return 1;   //return Sucess
    }
    else qDebug()<<"Can't Disconnect when not connected";
    return 0;   //Return Failure
}
