#include "VehicleTypes.h"

Compact::Compact()
{
    this->seatCosts = {"-", "5", "3", "3"};
    this->name = "compact";
    this->type = "owner's";
}

Compact::Compact(string name, string type)
{
    this->seatCosts = {"-", "5", "3", "3"};
    this->name = name;
    this->type = type;
}
