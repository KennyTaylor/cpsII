// Ken Taylor, CPET and Ben Brache, CRIM
#include "VehicleTypes.h"

Compact::Compact()
{
    this->seatCosts = {"-", "5", "3", "3"};
    this->name = "Compact";
    this->type = "";
}

Compact::Compact(string type)
{
    this->seatCosts = {"-", "5", "3", "3"};
    this->name = "Compact";
    this->type = type;
}
