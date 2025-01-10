#ifndef ROOM_H
#define ROOM_H

#include<iostream>

using namespace std;
class Room
{

private:
    string guestName;
    int roomNumber;
    int dailyRate;
    bool isOccupied;
    int extraExpenses;

public:
    Room(int numberRoom, int rateDaily);

    void CheckIn(const string &name);
    void CheckOut(int days);
    void ExtraExpenses(int amount);

    int getRoomNumber();
    bool getisOccupied();

    string getGuestName() const;
    void setGuestName(const string &newGuestName);
    int getDailyRate() const;
    void setExtraExpenses(int newExtraExpenses);
    int getExtraExpenses();
};

#endif // ROOM_H
