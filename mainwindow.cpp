#include "mainwindow.h"
#include"roomsdialog.h"
#include "./ui_mainwindow.h"
#include"extradialog.h"
#include<iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_CheckIn_clicked()
{
    RoomsDialog*roomsDialog=new RoomsDialog(this);
    roomsDialog->setIsChekinPressed(true);
    roomsDialog->setIsCheckOutPressed(false);


    auto ret=roomsDialog->exec();


    if(ret==QDialog::Accepted)
    {

    }
    else
    {

    }


}


void MainWindow::on_pushButton_CheckOut_clicked()
{
    RoomsDialog*roomsDialog=new RoomsDialog(this);
    roomsDialog->setIsChekinPressed(false);
    roomsDialog->setIsCheckOutPressed(true);


    auto ret=roomsDialog->exec();

    if(ret==QDialog::Accepted)
    {

    }
}


void MainWindow::on_pushButton_Extra_clicked()
{
    ExtraDialog*extraDialog=new ExtraDialog(this);
     RoomsDialog*roomsDialog=new RoomsDialog(this);

    roomsDialog->setIsChekinPressed(false);
    roomsDialog->setIsCheckOutPressed(false);

    auto ret=extraDialog->exec();

    if(ret==QDialog::Accepted)
    {

    }

}

