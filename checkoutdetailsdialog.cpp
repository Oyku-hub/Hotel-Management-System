#include "checkoutdetailsdialog.h"
#include "ui_checkoutdetailsdialog.h"
#include "roomsdialog.h"
#include"hotel.h"
#include"room.h"
#include <iostream>

using namespace std;

CheckOutDetailsDialog::CheckOutDetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckOutDetailsDialog)
{
    ui->setupUi(this);

    RoomsDialog*parentDialog=dynamic_cast<RoomsDialog*>(parent);
    int roomNo =parentDialog->getChoosenRoom();
    parentDialog->setChoosenRoom(roomNo);
    pDialog=parentDialog;
    QString str=QString::number(roomNo);
    ui->label_RoomNo->setText(str);

    Hotel*hotel=Hotel::getInstance();
    Room*room=hotel->findRoom(roomNo);

    QString strGuestName=QString::fromStdString(room->getGuestName());

    ui->lineEdit_CustomerName->setText(strGuestName);

}

CheckOutDetailsDialog::~CheckOutDetailsDialog()
{
    delete ui;
}

int CheckOutDetailsDialog::getTotalDays() const
{
    return totalDays;
}

void CheckOutDetailsDialog::setTotalDays(int newTotalDays)
{
    totalDays = newTotalDays;
}

void CheckOutDetailsDialog::on_pushButton_CalculateFree_clicked()
{
    bool ok;

    int days=ui->lineEdit_TotalDays->text().toInt(&ok);

    if(ok)
    {
        Hotel*hotel=Hotel::getInstance();
        Room*room=hotel->findRoom(pDialog->getChoosenRoom());
        int totalFee=days*room->getDailyRate()+room->getExtraExpenses();

        ui->lineEdit_TotalFree->setText(QString::number(totalFee));

    }
    else
    {
         ui->lineEdit_TotalFree->setText("Invalid value !!!");

    }


}


void CheckOutDetailsDialog::on_pushButton_CheckOut_clicked()
{

    bool ok;
    int days=ui->lineEdit_TotalDays->text().toInt(&ok);

    if(ok)
    {
        setTotalDays(days);
        accept();

    }
    else
    {
         ui->lineEdit_TotalDays->setText("Please enter the days !!!");
    }

}


void CheckOutDetailsDialog::on_pushButton_Cancel_clicked()
{
    reject();
}

