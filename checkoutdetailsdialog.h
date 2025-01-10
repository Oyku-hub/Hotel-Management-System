#ifndef CHECKOUTDETAILSDIALOG_H
#define CHECKOUTDETAILSDIALOG_H
#include "roomsdialog.h"

#include <QDialog>

namespace Ui {
class CheckOutDetailsDialog;
}

class CheckOutDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutDetailsDialog(QWidget *parent = nullptr);
    ~CheckOutDetailsDialog();

    int getTotalDays() const;
    void setTotalDays(int newTotalDays);

private slots:
    void on_pushButton_CalculateFree_clicked();

    void on_pushButton_CheckOut_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::CheckOutDetailsDialog *ui;
    int totalDays;
    RoomsDialog*pDialog;
};

#endif // CHECKOUTDETAILSDIALOG_H
