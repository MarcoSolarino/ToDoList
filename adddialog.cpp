#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    activity="  ";
    ui->dateEdit->setDate(QDate::currentDate());
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_clicked()
{
    activity=ui->lineEdit->text();
    AddDialog::close();

}

const QDate AddDialog::getDate(){
    QDate d=ui->dateEdit->date();
    return d;
}
