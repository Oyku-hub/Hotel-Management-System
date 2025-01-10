#include "detailsdialog.h"
#include "ui_detailsdialog.h"
#include"roomsdialog.h"
#include"room.h"

DetailsDialog::DetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetailsDialog)
{
    ui->setupUi(this);

    RoomsDialog*parentDialog=dynamic_cast<RoomsDialog*>(parent);
    pDialog=parentDialog;
    int roomNo =parentDialog->getChoosenRoom();
    QString str=QString::number(roomNo);
    ui->label->setText(str);

}

DetailsDialog::~DetailsDialog()
{
    delete ui;
}

void DetailsDialog::on_pushButton_Ok_details_clicked()
{
    Room*room;

    QString name=ui->lineEdit->text();


    if(!name.isEmpty())
    {
         accept();
        pDialog->setCustomerName(name);

    }
    else
    {
          reject();

    }





}


void DetailsDialog::on_pushButton_Cancel_details_clicked()
{

    reject();
}

