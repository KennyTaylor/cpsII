#include "Vehicle.h"

Vehicle::Vehicle()
{
    this->name = "name's";
    this->type = "vehicle";
}
Vehicle::Vehicle(string name, string type)
{
    this->name = name;
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
string Vehicle::print() const
{
    string temp = "";
    // string temp = "(-) (" + this->seatCosts.at(0) + ")\n";
    for (int i = 0; i < this->seatCosts.size(); i++)
    {
        temp += "(" + this->seatCosts.at(i) + ")";
        if (i == 1)
        {
            temp += "\n";
        }
    }
    return this->name + " " + this->type + "\n" + temp;
}