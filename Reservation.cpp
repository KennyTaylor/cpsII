// Ken Taylor, CPET and Ben Brache, CRIM
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

// simple modify member function
void Reservation::modify(string newCarType, string newCarName)
{
    this->carName = newCarName;
    this->carType = newCarType;
}
// note: not really printing, returning a string
string Reservation::print() const
{
    return this->name + " has a reservation in " + this->carName + " " + this->carType + ", cost " + to_string(this->credits) + " credits";
}
