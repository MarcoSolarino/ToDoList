#ifndef TODOLIST_H
#define TODOLIST_H


#include"subject.h"
#include"QList"
#include"activity.h"
#include"QDate"
#include "QFile"
#include"QIODevice"
#include"QTextStream"

class ToDoList: public Subject{
public:

    ToDoList(){}

    virtual void addObserver(Observer *o){
        observers.push_back(o);
    }
    virtual void removeObserver(Observer *o){
        observers.removeOne(o);
    }
    virtual void notify(){
        for(Observer* observer: observers)
            observer->update();
    }
    void addActivity(Activity* a){
        list.push_back(a);
        notify();
    }

    void pushBack(Activity* a){
        list.push_back(a);
    }

    void removeActivity(Activity* a){
        list.removeOne(a);
        notify();
    }

    void deleteAll(){
        list.clear();
        //saveList();
        notify();
    }

    void clearList(){
        list.clear();
    }

    void saveList();

    void loadList();

    QList<Activity*> getList();

    QList<Activity*> search(QDate d);

private:
    QList<Activity*> list;
    QList<Observer*> observers;
};

#endif // TODOLIST_H
