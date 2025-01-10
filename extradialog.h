#ifndef EXTRADIALOG_H
#define EXTRADIALOG_H

#include <QDialog>

namespace Ui {
class ExtraDialog;
}

class ExtraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExtraDialog(QWidget *parent = nullptr);
    ~ExtraDialog();

private slots:
    void on_pushButton_Ok_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::ExtraDialog *ui;
};

#endif // EXTRADIALOG_H
