#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Vehicle
{
protected:
    string name, type;
    vector<string> seatCosts = {"-", "5"};

public:
    Vehicle();
    Vehicle(string name, string type);

    string getName();
    string getType();
    vector<string> getSeatCosts();
    string print() const;
};
