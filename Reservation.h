#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Reservation
{
private:
    string name, carType, carName;
    int credits, creditsRemaining, carNum, seatNum;

public:
    Reservation();
    Reservation(string name, string carType, string carName);
    Reservation(string name, string type, int credits);

    string getName()
    {
        return this->name;
    }
    string getCarType()
    {
        return this->carType;
    }
    int getCredits()
    {
        return this->credits;
    }
    string getCarName()
    {
        return this->carName;
    }
    void modify(string newCarType, string newCarName);
    // void remove();
    string print() const;
};
