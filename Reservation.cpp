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

void Reservation::modify(string newCarType, string newCarName)
{
    this->carName = newCarName;
    this->carType = newCarType;
}
void Reservation::remove()
{
    this->modify("Vehicle", "Blank");
}
//todo: what should a reservation print? NAME has a reservation in NAME CAR for NUM credits
string Reservation::print() const
{
    return this->name + "has a reservation in " + this->carName + " " + this->carType + ", cost " + to_string(this->credits) + " credits";
}