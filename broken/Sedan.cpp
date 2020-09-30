#include "Sedan.h"

Sedan::Sedan()
{
    this->seatCosts = {"-", "5", "2", "1", "2"};
    this->name = "sedan";
    this->type = "owner's";
}

Sedan::Sedan(string name, string type)
{
    this->seatCosts = {"-", "5", "2", "1", "2"};
    this->name = name;
    this->type = type;
}
