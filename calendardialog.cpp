#include "calendardialog.h"
#include "ui_calendardialog.h"
#include<QTextCharFormat>


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
    update();

}

CalendarDialog::~CalendarDialog()
{
    delete ui;
}

void CalendarDialog::update(){
    QList<Activity*> list=toDoList->getList();
    QTextCharFormat dayHighlight;
    dayHighlight.setBackground(Qt::yellow);
    for (auto itr=list.begin(); itr!=list.end();itr++){
        QDate aDay=(*itr)->getDate();
        ui->calendarWidget->setDateTextFormat(aDay,dayHighlight);
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
