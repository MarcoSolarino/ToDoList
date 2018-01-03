#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDialog>
#include"observer.h"
#include"todolist.h"
#include"controller.h"

namespace Ui {
class CalendarDialog;
}

class CalendarDialog : public QDialog, public Observer
{
    Q_OBJECT

public:
    explicit CalendarDialog(ToDoList* l,Controller* c,QWidget *parent = 0);
    ~CalendarDialog();
    virtual void update();
    QDate getSelDate();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::CalendarDialog *ui;
    ToDoList* toDoList;
    Controller* controller;
    QDate selDate;
};

#endif // CALENDARDIALOG_H
