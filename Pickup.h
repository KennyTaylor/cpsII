#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;
class Pickup : public Vehicle
{
public:
    Pickup();
    Pickup(string name, string type);

    // string getName();
    // string getType();
    // vector<string> getSeatCosts();
    // string print() const;
};
