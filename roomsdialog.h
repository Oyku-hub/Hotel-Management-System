#ifndef ROOMSDIALOG_H
#define ROOMSDIALOG_H


#include <QDialog>

namespace Ui {
class RoomsDialog;
}

class RoomsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomsDialog(QWidget *parent = nullptr);
    ~RoomsDialog();
    void ButtonColorChange(int roomNumber,QPushButton*button);

    int getChoosenRoom() const;
    void setChoosenRoom(int newChoosenRoom);

    QString getCustomerName() const;
    void setCustomerName(const QString &newCustomerName);

    bool getIsChekinPressed() const;
    void setIsChekinPressed(bool newIsChekinPressed);

    bool getIsCheckOutPressed() const;
    void setIsCheckOutPressed(bool newIsCheckOutPressed);


private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_clicked();

    void on_pushButton_101_clicked();

    void ProcessButton(int roomNumber,QPushButton*button);

    void on_pushButton_102_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_201_clicked();

    void on_pushButton_202_clicked();

    void on_pushButton_203_clicked();

private:
    Ui::RoomsDialog *ui;
    int choosenRoom;
    QString customerName;
    bool isChekinPressed;
    bool isCheckOutPressed;



};

#endif // ROOMSDIALOG_H
