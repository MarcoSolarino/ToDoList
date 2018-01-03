#include "calendardialog.h"
#include "ui_calendardialog.h"


CalendarDialog::CalendarDialog(ToDoList *l, Controller *c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarDialog)
{
    toDoList=l;
    toDoList->addObserver(this);
    controller=c;
    ui->setupUi(this);
    toDoList->loadList();
    selDate=QDate::currentDate();

}

CalendarDialog::~CalendarDialog()
{
    delete ui;
}

void CalendarDialog::update(){
    QList<Activity*> list=toDoList->getList();
    for (auto itr=list.begin(); itr!=list.end();itr++){

    }
}

void CalendarDialog::on_calendarWidget_clicked(const QDate &date)
{
    selDate=date;
    CalendarDialog::close();

}

QDate CalendarDialog::getSelDate(){
    return ui->calendarWidget->selectedDate();
}
