#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include "roomsdialog.h"
#include <QDialog>

namespace Ui {
class DetailsDialog;
}

class DetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsDialog(QWidget *parent = nullptr);
    ~DetailsDialog();

private slots:
    void on_pushButton_Ok_details_clicked();

    void on_pushButton_Cancel_details_clicked();

private:
    Ui::DetailsDialog *ui;
    RoomsDialog*pDialog;

};

#endif // DETAILSDIALOG_H
