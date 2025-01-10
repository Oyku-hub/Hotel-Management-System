#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"
#include<vector>
#include<iostream>

class Hotel
{
private:

    static Hotel*instance;
    vector<Room>rooms;
    Hotel();
public:

    static Hotel*getInstance();
    Room*findRoom(int roomNumber);
    ~Hotel();



};

#endif // HOTEL_H
