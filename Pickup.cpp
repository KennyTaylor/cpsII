#include "Pickup.h"
#include <vector>

Pickup::Pickup()
{
    this->seatCosts = {"5"};
    this->name = "car_name";
    this->type = "pickup";
}

Pickup::Pickup(string name, string type)
{
    this->seatCosts = {"5"};
    this->name = name;
    this->type = type;
}
