#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include<QDate>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = 0);
    ~EditDialog();
    const QString getActivity();
    const QDate getDate();
    bool getButtonClicked();
    void setActivity(const QString& a);
    void setDate(const QDate& d);

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditDialog *ui;
    QString activity;
    QDate deadLine;
    bool buttonClicked;
};

#endif // EDITDIALOG_H
