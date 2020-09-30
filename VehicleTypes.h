#include "Vehicle.h"

using namespace std;
class Pickup : public Vehicle
{
public:
    Pickup();
    Pickup(string name, string type);
};
class Sedan : public Vehicle
{
public:
    Sedan();
    Sedan(string name, string type);
};
class Compact : public Vehicle
{
public:
    Compact();
    Compact(string name, string type);
};
