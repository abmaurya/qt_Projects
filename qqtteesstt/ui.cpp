#include "ui.h"

UI::UI(QApplication *app){
    tabWidget = new QTabWidget(this);
    appl = app;
    flag = false;
    konnect = new Clients();
    evres = new serving();
    createUI();
}

//UI::UI(){

//}

UI::~UI(){
    delete tabWidget;
    //delete appl;
    delete konnect;
    delete evres;
}

void UI::createUI()
{
    QWidget *mainWidget =new QWidget(tabWidget);
    QGridLayout *layout = new QGridLayout(mainWidget);
    //QByteArray b_arr;

    //****Button Declarations****
    QPushButton *button1 = new QPushButton("Close Server",mainWidget);
    QPushButton *button2 = new QPushButton("Connect",mainWidget);
    QPushButton *Quit = new QPushButton("Quit",mainWidget);
    QPushButton *button4 = new QPushButton("Serve",mainWidget);

    button1->setStyleSheet("background-color : blue");
    button2->setStyleSheet("background-color : green");
    Quit->setStyleSheet("background-color : red");
    button4->setStyleSheet("background-color : grey");

    //****Signal -Slot Connections****
    connect(button1,SIGNAL(clicked(bool)),evres, SLOT(closin()));
    connect(button1,SIGNAL(clicked(bool)),this,SLOT(destroyChatUI()));
    connect(button2,SIGNAL(clicked(bool)),konnect, SLOT(connecting()));
    connect(button2,SIGNAL(clicked(bool)),this, SLOT(createChatUI()));
    connect(Quit,SIGNAL(clicked(bool)),appl, SLOT(quit()));
    connect(button4,SIGNAL(clicked(bool)),evres, SLOT(serv()));

    //****Setting Up Window Layout****
    layout->addWidget(Quit,2,2);
    layout->addWidget(button1,0,2);
    layout->addWidget(button2,2,0);
    layout->addWidget(button4,0,0);

    mainWidget->setLayout(layout);
    mainWidget->setStyleSheet("background-color: pink");

    //****Setting Window Title****
    tabWidget->setWindowTitle("TestApp");

    //****Calling Show So that mainWidget named Window is shown first on execution****
    tabWidget->addTab(mainWidget,"IX");

    tabWidget->show();
}

/*
 * **Creates UI for Chat
 */
void UI::createChatUI(){
    //Declarations
    if(konnect->connected){
        QWidget *client_ui_widget = new QWidget(tabWidget);
        QGridLayout *lot =  new QGridLayout(client_ui_widget);
        QTextEdit *input = new QTextEdit("",client_ui_widget);
        QTextBrowser  *show = new QTextBrowser(client_ui_widget);
        QPushButton *sendmsg = new QPushButton("Send",client_ui_widget);
        QPushButton *closex = new QPushButton("Close",client_ui_widget);

        show->setText("your messages");

        sendmsg->setStyleSheet("background-color: green");
        closex->setStyleSheet("background-color: red");

        //Setting UI Layout
        lot->addWidget(show,0,0);
        lot->addWidget(closex,0,1);
        lot->addWidget(input,1,0);
        lot->addWidget(sendmsg,1,1);
        client_ui_widget->setLayout(lot);

        //Connections
        connect(closex,SIGNAL(clicked(bool)),this,SLOT(destroyChatUI()));

        //Showing Window
        if(!flag){
            tabWidget->addTab(client_ui_widget,"ChatWindow");
            flag = true;
            tabWidget->setCurrentWidget(client_ui_widget);

        }
        //Window Destruction
        client_ui_widget->destroyed(client_ui_widget);
    }
}

int UI::destroyChatUI(){
    if(evres->status == NEVER_SERVED|| !konnect->connected)
        return 0;
    if(konnect->disconnecting())
        tabWidget->removeTab(1);
    flag = false;
    return 0;

}
