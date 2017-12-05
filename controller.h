#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"todolist.h"
#include"QString"
#include"activity.h"

class Controller
{
public:
    Controller(ToDoList* l):list(l){}
    void write(QString t,QDate d,bool cS);
    void clear();
    QList<Activity*> search(QDate d);
    void save(QString t,QDate d,bool cS);
private:
    ToDoList* list;
};

#endif // CONTROLLER_H
