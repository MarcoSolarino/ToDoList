#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

    const QString getActivity(){
        return activity;
    }

    const QDate getDate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddDialog *ui;
    QString activity;
};

#endif // ADDDIALOG_H
