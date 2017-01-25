#include "serving.h"

serving::serving(){
    status = NEVER_SERVED;
}

serving::~serving(){
    serv_sock.deleteLater();
}

void serving::closin(){
    if(status == SERVING){
        serv_sock.close();
        qDebug()<<"The serving has been stopped";
        status = SERVER_CLOSED;
    }
    else qDebug()<<"Can't Close when it's not open";
}

void serving::serv(){
    if(status == SERVER_CLOSED || status == NEVER_SERVED){
        serv_sock.listen(host,1995);
        if(!serv_sock.isListening())
            qDebug()<<"The serving has not been started";
        else{
            qDebug()<<"The serving has been started";
            status = SERVING;
        }
    }
    else qDebug()<<"Serving already";
}


void onNewConnection(){
}
