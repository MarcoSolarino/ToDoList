#include "todolist.h"
#include"stdio.h"



void ToDoList::saveList(){
    QString filename="./list.txt";
    QFile file(filename);
    QTextStream memo(&file);
    if(file.open(QIODevice::WriteOnly)){
        for(auto itr=list.begin();itr!=list.end();itr++){
            if((*itr)->getDone())
                memo<<"0,  ";
            else
                memo<<"1,  ";
            memo<<(*itr)->getTask()<<",  "<<(*itr)->getDate().toString("dd.MM.yyyy")<<"\n";

        }
    }
}

void ToDoList::loadList(){
    QString filename="./list.txt";
    QFile file(filename);
    QTextStream memo(&file);
    if(file.open(QIODevice::ReadOnly)){
        while(!memo.atEnd()){
            QString line=memo.readLine();
            QString t=line.split(",  ").at(1);
            QString dL=line.split(",  ").at(2);
            QDate date=QDate::fromString(dL,"dd.MM.yyyy");
            QString d=line.split(",  ").first();
            bool done;
            if(d=="1")
                done=false;
            else if(d=="0")
                done=true;
            Activity* currentActivity=new Activity(t,date,done);
            list.push_back(currentActivity);
            notify();
        }

    }
}

QList<Activity*> ToDoList::search(QDate d){
    QList<Activity*> sList;
    for(auto itr=list.begin();itr!=list.end();itr++){
        if((*itr)->getDate()==d)
            sList.push_back((*itr));
    }
    return sList;
}

QList<Activity*> ToDoList::getList(){
    QList<Activity*> l;
    for(auto itr=list.begin();itr!=list.end();itr++){
        l.push_back((*itr));
    }
    return l;
}
