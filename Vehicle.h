// Ken Taylor, CPET and Ben Brache, CRIM
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
// parent class for the three vehicle types
class Vehicle
{
protected: // all 3 types of vehicles will inherit these data members, so they are protected instead of private.s
    string name, type;
    vector<string> seatCosts = {"-", "5"}; // dash for occupied seats, drivers seat is always occupied.
    // the rest of the seats are represented by the amount of points it takes to purchase a ride in that seat

public:
    Vehicle();
    Vehicle(string type); // note: type is from previous naming scheme, now holds the car's paint color

    // getters and setters
    string getName();
    string getType();
    vector<string> getSeatCosts();
    void setSeatCosts(vector<string> seatCosts);
    string print() const;
};
