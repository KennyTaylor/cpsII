#include "Reservation.h"
using namespace std;

int main()
{
    Reservation testRes("test player", "pickup", "red"); // Create an object of MyClass

    cout << testRes.getName() << " has a reservation in a " << testRes.getCarName() << " " << testRes.getCarType() << endl;

    return 0;
}
