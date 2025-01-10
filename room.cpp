#include "room.h"

string Room::getGuestName() const
{
    return guestName;
}

void Room::setGuestName(const string &newGuestName)
{
    guestName = newGuestName;
}

int Room::getDailyRate() const
{
    return dailyRate;
}

void Room::setExtraExpenses(int newExtraExpenses)
{
    extraExpenses = newExtraExpenses;
}

Room::Room(int numberRoom, int rateDaily) {

     guestName ="";
     roomNumber=numberRoom;
     isOccupied=false;
     dailyRate=rateDaily;
     extraExpenses=0;

}

void Room::CheckIn(const string &name)
{
    if(!isOccupied)
    {
        guestName=name;
        isOccupied=true;
    }
    else
    {

    }


}
void Room::CheckOut(int days)
{
    if(isOccupied)
    {
        int totalCost=(dailyRate*days)+extraExpenses;
        guestName ="";
        isOccupied=false;
        extraExpenses=0;
    }
    else
    {

    }

}
void Room::ExtraExpenses(int amount)
{
    if(isOccupied)
    {
         extraExpenses+=amount;
    }


}
int Room::getExtraExpenses()
{
    return extraExpenses;
}
int Room::getRoomNumber()
{
    return roomNumber;

}

bool Room::getisOccupied()
{
    return isOccupied;
}
