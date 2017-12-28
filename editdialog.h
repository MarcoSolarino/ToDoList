#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

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
    void setActivity(const QString& a);
    void setDate(const QDate& d);

private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
