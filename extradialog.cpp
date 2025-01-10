#include "extradialog.h"
#include "ui_extradialog.h"
#include"hotel.h"
#include <QMessageBox>
#include"room.h"

ExtraDialog::ExtraDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExtraDialog)
{
    ui->setupUi(this);
}

ExtraDialog::~ExtraDialog()
{
    delete ui;
}

void ExtraDialog::on_pushButton_Ok_clicked()
{

    bool okAmount;
    int amount=ui->lineEdit_AmountSpend->text().toInt(&okAmount);


    bool okRoomNumber;
    int roomNo=ui->lineEdit_roomNumber->text().toInt(&okRoomNumber);



    if(okRoomNumber && okAmount)
    {
        Hotel*hotel=Hotel::getInstance();
        Room*room=hotel->findRoom(roomNo);
        if(room!=nullptr)
        {
            if(!room->getisOccupied())
            {
                 QMessageBox::critical(nullptr, "Error", "No expense the empty room!");
            }
             room->ExtraExpenses(amount);



        }
         accept();

    }
    else
    {
        reject();
    }


}


void ExtraDialog::on_pushButton_Cancel_clicked()
{
    reject();
}

