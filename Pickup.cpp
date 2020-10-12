// Ken Taylor, CPET and Ben Brache, CRIM
#include "VehicleTypes.h"

Pickup::Pickup()
{
    this->seatCosts = {"-", "5"};
    this->name = "owner";
    this->type = "color";
}

Pickup::Pickup(string type)
{
    this->seatCosts = {"-", "5"};
    this->name = "Pickup";
    this->type = type;
}
