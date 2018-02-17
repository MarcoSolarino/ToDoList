#ifndef ACTIVITY_H
#define ACTIVITY_H

#include<QString>
#include<QDate>


class Activity{
public:
    explicit Activity(QString t, QDate dL, bool d=false):task(t),deadLine(dL),done(d){}
    QString getTask() const{
        return task;
    }
    bool getDone() const{
        return done;
    }
    QDate getDate()const{
        return deadLine;
    }

    void setTask(const QString t){
        task=t;
    }

    void setDone(const bool d){
        done=d;
    }



private:
    QString task;
    QDate deadLine;
    bool done;
};


#endif // ACTIVITY_H
