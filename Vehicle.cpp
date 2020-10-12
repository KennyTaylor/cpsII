// Ken Taylor, CPET and Ben Brache, CRIM
#include "Vehicle.h"

Vehicle::Vehicle()
{
    this->name = "Vehicle";
    this->type = "vehicle";
}
Vehicle::Vehicle(string type)
{
    this->name = "Vehicle";
    this->type = type;
}
string Vehicle::getName()
{
    return this->name;
}
string Vehicle::getType()
{
    return this->type;
}
vector<string> Vehicle::getSeatCosts()
{
    return this->seatCosts;
}

// example output:
// Red Pickup
// (-)(5)
//
string Vehicle::print() const
{
    string temp = "";
    for (int i = 0; i < this->seatCosts.size(); i++)
    {
        temp += "(" + this->seatCosts.at(i) + ")";
        if (i == 1)
        {
            temp += "\n";
        }
    }
    return this->type + " " + this->name + "\n" + temp + "\n";
}
void Vehicle::setSeatCosts(vector<string> seatCosts)
{
    this->seatCosts = seatCosts;
}