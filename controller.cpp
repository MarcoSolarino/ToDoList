#include "controller.h"
#include"activity.h"


void Controller::write(QString t, QDate d,bool cS){
    Activity* activity=new Activity(t,d,cS);
    list->addActivity(activity);
}

void Controller::clear(){
    list->deleteAll();
    list->saveList();
}

QList<Activity*> Controller::search(QDate d){
    QList<Activity*> srcList=list->search(d);
    return srcList;
}

void Controller::save(QString t,QDate d,bool cS){
    Activity* a=new Activity(t,d,cS);
    list->pushBack(a);
    list->saveList();
}
