//#include <QRadioButton>
#include <QDebug>
#include <QTcpSocket>
#include <QIcon>
#include <QTabWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QTextBrowser>
#include <QApplication>

#include "serving.h"
#include "Clients.h"

//#include <QSplashScreen>

#ifndef UI_H
#define UI_H


class UI : public QWidget
{
    Q_OBJECT

    QTabWidget *tabWidget;
    QApplication *appl;
    bool flag;
    Clients *konnect;
    serving *evres ;
    //QApplication appl;


public:
    explicit UI(QApplication *app);
    //UI();
    ~UI();
    void createUI();

public slots:
    void createChatUI();
    int destroyChatUI();

};

#endif // UI_H
