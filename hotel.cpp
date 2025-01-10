#include "hotel.h"

using namespace std;

Hotel*Hotel::instance=nullptr; //init

Hotel::Hotel() {

    rooms.emplace_back(101,250);

    rooms.emplace_back(102,250);
    rooms.emplace_back(103,250);

    rooms.emplace_back(201,300);
    rooms.emplace_back(202,300);
    rooms.emplace_back(203,400); //suite room


}

Hotel*Hotel::getInstance()
{
    if(instance==nullptr)
    {
        instance=new Hotel();
    }
    return instance;
}
Room*Hotel::findRoom(int roomNumber)
{
    for(auto &room:rooms)
    {
        if(room.getRoomNumber()==roomNumber)
        {
            return &room;
        }
    }
    return nullptr;

}

Hotel::~Hotel()
{
    delete instance;

}
