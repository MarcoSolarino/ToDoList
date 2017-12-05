#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToDoList* l= new ToDoList;
    Controller* c=new Controller(l);
    MainWindow w(l,c);
    w.show();

    return a.exec();
}
