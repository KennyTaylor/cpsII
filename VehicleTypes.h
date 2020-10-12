// Ken Taylor, CPET and Ben Brache, CRIM
#include "Vehicle.h"
using namespace std;
class Pickup : public Vehicle
{
public:
    Pickup();
    Pickup(string type);
};

class Sedan : public Vehicle
{
public:
    Sedan();
    Sedan(string type);
};

class Compact : public Vehicle
{
public:
    Compact();
    Compact(string type);
};
