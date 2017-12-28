#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    buttonClicked=false;
}

EditDialog::~EditDialog()
{
    delete ui;
}

const QString EditDialog::getActivity(){
    return ui->lineEdit->text();
}

const QDate EditDialog::getDate(){
    return ui->dateEdit->date();
}

void EditDialog::setActivity(const QString &a){
    ui->lineEdit->setText(a);
}

void EditDialog::setDate(const QDate &d){
    ui->dateEdit->setDate(d);
}

void EditDialog::on_pushButton_clicked()
{
    buttonClicked=true;
    EditDialog::close();
}

bool EditDialog::getButtonClicked(){
    return buttonClicked;
}
