#include "Reservation.h"

// default constructor
Reservation::Reservation()
{
    this->carName = "";
    this->carType = "Vehicle";
    this->name = "Player Name";
}
// constructor
Reservation::Reservation(string name, string carType, string carName)
{
    this->carName = carName;
    this->carType = carType;
    this->name = name;
}
Reservation::Reservation(string name, string type, int credits)
{
    this->credits = credits;
    this->carType = type;
    this->name = name;
}

void Reservation::modify(string newCarType, string newCarName)
{
    this->carName = newCarName;
    this->carType = newCarType;
}
// void Reservation::remove()
// {
//     this->modify("Vehicle", "Blank");
// }
//todo: Looks fine to me. If it's not exactly what he wants, we can talk to him on Wednesday, but for now, I think it's fine.
string Reservation::print() const
{
    return this->name + " has a reservation in " + this->carName + " " + this->carType + ", cost " + to_string(this->credits) + " credits";
}
