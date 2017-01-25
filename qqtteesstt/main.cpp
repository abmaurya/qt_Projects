#include <QApplication>

#include "ui.h"

using namespace Qt;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("/home/abm/Documents/Qt_Pro/qqtteesstt/Chess_Texture.png"));
    UI ui(&app);
    ui.show();
    return app.exec();



//    tab->deleteLater();
    //    QTabWidget *tab = new QTabWidget();
    //    //****Setting Window Title****
    //    tab->setWindowTitle("TestApp");

    //    UI ui(tab,&app);
    //    UI ui(&app);
        //UI ui(&app);
//    tab->show();
}
