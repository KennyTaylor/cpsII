// Ken Taylor, CPET and Ben Brache, CRIM
#include "VehicleTypes.h"

Sedan::Sedan()
{
    this->seatCosts = {"-", "5", "2", "1", "2"};
    this->name = "Sedan";
    this->type = "";
}

Sedan::Sedan(string type)
{
    this->seatCosts = {"-", "5", "2", "1", "2"};
    this->name = "Sedan";
    this->type = type;
}
