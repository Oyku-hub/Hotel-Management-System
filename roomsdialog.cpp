#include "roomsdialog.h"
#include "ui_roomsdialog.h"
#include"detailsdialog.h"
#include"checkoutdetailsdialog.h"
#include"extradialog.h"
#include"room.h"
#include"hotel.h"

RoomsDialog::RoomsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomsDialog)
{
    ui->setupUi(this);
    ButtonColorChange(101,ui->pushButton_101);
    ButtonColorChange(102,ui->pushButton_102);
    ButtonColorChange(103,ui->pushButton_103);
    ButtonColorChange(201,ui->pushButton_201);
    ButtonColorChange(202,ui->pushButton_202);
    ButtonColorChange(203,ui->pushButton_203);




}

RoomsDialog::~RoomsDialog()
{
    delete ui;
}


void RoomsDialog::on_pushButton_11_clicked()
{

    accept();

}

void RoomsDialog::ButtonColorChange(int roomNumber,QPushButton*button)
{
    Hotel*hotel=Hotel::getInstance();
    Room*room=hotel->findRoom(roomNumber);

    if (!room->getisOccupied()) {
        button->setStyleSheet(
            "QPushButton {"
            "   background-color: blue;"
            "   color: white;"
            "   font-weight: bold;"
            "   border-radius: 10px;"
            "   font-size: 18px;"
            "}"
            "QPushButton:hover {"
            "   background-color: green;"
            "}"
            );
    } else {
        button->setStyleSheet(
            "QPushButton {"
            "   background-color: red;"
            "   color: white;"
            "   font-weight: bold;"
            "   border-radius: 10px;"
            "   font-size: 18px;"
            "}"
            "QPushButton:hover {"
            "   background-color: green;"
            "}"
            );

    }
}

void RoomsDialog::on_pushButton_12_clicked()
{

    reject();

}



void RoomsDialog::on_pushButton_clicked()
{


}




void RoomsDialog::ProcessButton(int roomNumber,QPushButton*button)
{
    Hotel*hotel=Hotel::getInstance();
    Room*room=hotel->findRoom(roomNumber);

    if(getIsChekinPressed())
    {
        cout<<"Check in ile geldi"<<endl;
        if(!room->getisOccupied())
        {
            setChoosenRoom(roomNumber);
            DetailsDialog*detailsDialog=new DetailsDialog(this);
            auto ret=detailsDialog->exec();

            if(ret==QDialog::Accepted)
            {
                room->CheckIn(getCustomerName().toStdString());
                ButtonColorChange(roomNumber,button);
            }

        }

    }
    if(getIsCheckOutPressed())

    {
         cout<<"Check out ile geldi"<<endl;

            if(room->getisOccupied())
            {

                setChoosenRoom(roomNumber);
                CheckOutDetailsDialog*checkOutDetailsDialog=new CheckOutDetailsDialog(this);
                auto ret=checkOutDetailsDialog->exec();

                if(ret==QDialog::Accepted)
                {
                    room->CheckOut(checkOutDetailsDialog->getTotalDays());
                    ButtonColorChange(roomNumber,button);

                }

            }


    }
}
QString RoomsDialog::getCustomerName() const
{
    return customerName;
}

void RoomsDialog::setCustomerName(const QString &newCustomerName)
{
    customerName = newCustomerName;
}

int RoomsDialog::getChoosenRoom() const
{
    return choosenRoom;
}

void RoomsDialog::setChoosenRoom(int newChoosenRoom)
{
    choosenRoom = newChoosenRoom;
}

void RoomsDialog::on_pushButton_101_clicked()
{
    ProcessButton(101,ui->pushButton_101);

}

void RoomsDialog::on_pushButton_102_clicked()
{
 ProcessButton(102,ui->pushButton_102);
}


void RoomsDialog::on_pushButton_103_clicked()
{
 ProcessButton(103,ui->pushButton_103);
}


void RoomsDialog::on_pushButton_201_clicked()
{
 ProcessButton(201,ui->pushButton_201);
}


void RoomsDialog::on_pushButton_202_clicked()
{
 ProcessButton(202,ui->pushButton_202);
}


void RoomsDialog::on_pushButton_203_clicked()
{
     ProcessButton(203,ui->pushButton_203);

}

bool RoomsDialog::getIsCheckOutPressed() const
{
    return isCheckOutPressed;
}

void RoomsDialog::setIsCheckOutPressed(bool newIsCheckOutPressed)
{
    isCheckOutPressed = newIsCheckOutPressed;
}


bool RoomsDialog::getIsChekinPressed() const
{
    return isChekinPressed;
}

void RoomsDialog::setIsChekinPressed(bool newIsChekinPressed)
{
    isChekinPressed = newIsChekinPressed;
}

