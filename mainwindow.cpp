#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QStringList"
#include"activity.h"
#include<QMessageBox>
#include"adddialog.h"

MainWindow::MainWindow(ToDoList* l,Controller* c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    toDoList=l;
    toDoList->addObserver(this);
    controller=c;
    ui->setupUi(this);
    toDoList->loadList();


}

MainWindow::~MainWindow()
{
    toDoList->removeObserver(this);
    delete ui;
}

void MainWindow::update(){
    ui->listWidget->clear();
    QListWidgetItem* item;
    QList<Activity*> list=toDoList->getList();
    QString t,d;
    bool cS;
    for(auto itr=list.begin();itr!=list.end();itr++){
        t=(*itr)->getTask();
        d=(*itr)->getDate().toString("dd.MM.yyyy");
        cS=(*itr)->getDone();
        item=new QListWidgetItem(t+"\n"+d,ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(cS)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actionsave_triggered()
{
    toDoList->clearList();
    for(int row=0;row<ui->listWidget->count();row++){
        QListWidgetItem* item=ui->listWidget->item(row);
        bool cS;
        if(item->checkState()==Qt::Checked)
            cS=true;
        else
            cS=false;
        QString task=item->text().split("\n").at(0);
        QString date=item->text().split("\n").at(1);
        QDate dL=QDate::fromString(date,"dd.MM.yyyy");
        controller->save(task,dL,cS);
    }
}

void MainWindow::on_actiondelete_lit_triggered()
{
    controller->clear();
}



void MainWindow::on_actionsave_and_exit_triggered()
{
    on_actionsave_triggered();
    QApplication::quit();
}

void MainWindow::on_actiondelete_selected_triggered()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
    on_actionsave_triggered();
}

void MainWindow::on_actionedit_selected_triggered()
{
    QListWidgetItem* itemSelected=ui->listWidget->currentItem();
    QString t=ui->lineEdit->text();
    QString d=ui->calendarWidget->selectedDate().toString("dd.MM.yyyy");

    if(!ui->listWidget->isItemSelected(itemSelected))
        ui->label->setText("Select an activity to edit!");
    else{
        itemSelected->setText(t+"\n"+d);
        }
    on_actionsave_triggered();
    ui->lineEdit->clear();
}



void MainWindow::on_actionundo_triggered()
{
    update();
}

void MainWindow::on_actionsearch_triggered()
{
    QList<Activity*> srcList=controller->search(ui->calendarWidget->selectedDate());
    QListWidgetItem* item;
    ui->listWidget->clear();
    QString t;
    QString d;
    bool cS;
    for(auto itr=srcList.begin();itr!=srcList.end();itr++){
        t=(*itr)->getTask();
        d=(*itr)->getDate().toString("dd.MM.yyyy");
        cS=(*itr)->getDone();
        item=new QListWidgetItem(t+"\n"+d,ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(cS)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState((Qt::Unchecked));
    }
}

void MainWindow::on_actionnew_triggered()
{
    AddDialog aDialog;
    aDialog.setModal(true);
    aDialog.exec();

    QString t=aDialog.getActivity();
    QDate d=ui->calendarWidget->selectedDate();
    bool cS=false;
    controller->write(t,d,cS);
    ui->lineEdit->clear();
}


