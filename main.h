// Ken Taylor, CPET and Ben Brache, CRIM
#ifndef MAIN_H
#define MAIN_H
#include <vector>
#include "Reservation.h"
#include "VehicleTypes.h"

using namespace std;
/**
 * delete the specified reservation (by index), using a reference to the reservations vector.
 */
int deleteReservation(int &reservationID, vector<Reservation> &reservations, vector<string> &names_db, vector<string> &points_db) // forward declaration of helper function, can go in helpers.h
{
    cout << "enter reservation ID to delete: ";
    cin >> reservationID;
    int credits;
    string name;
    while (reservationID < 0 && reservationID > 17)
    {
        cout << "enter a valid ID between 0 and 17: ";
        cin >> reservationID;
    }
    credits = reservations.at(reservationID).getCredits();
    name = reservations.at(reservationID).getName();
    for (int i = 0; i < names_db.size(); i++)
    {
        if (names_db.at(i) == name)
        {
            points_db.at(i) += credits; // refund the person whose reservation you are removing
            cout << name << " was refunded " << credits << " credits" << endl;
            break;
        }
    }
    reservations.erase(reservations.begin() + reservationID);

    cout << "reservation " << reservationID << " was deleted" << endl;
    return credits; // maybe in error case we can return something else
}

/**
 * write the updated list of passengers and points when quit is chosen.
 */
void outputFile(vector<string> drivers, vector<string> names_db, vector<string> points_db, string filename)
{
    ofstream myfile(filename);
    if (myfile.is_open())
    {
        for (int i = 0; i < drivers.size(); i++)
        {
            myfile << drivers.at(i) << "\n";
        }
        for (int i = 0; i < names_db.size(); i++)
        {
            myfile << names_db.at(i) << " " << points_db.at(i) << "\n";
        }
        // cout << file;
        myfile.close();
    }
    else
        cout << "Unable to open file";
}

/**
 * simple helper function that checks if the given seat (string) is free in the given car (represented as a list of seat costs), and if it is, writes a '-' in that seat.
 */
vector<string> takeSeatIfFree(vector<string> seatCosts, string seat)
{
    bool seatFlag = false;
    for (int i = 0; i < seatCosts.size(); i++)
    {
        if (seatCosts.at(i) == seat)
        {
            seatCosts.at(i) = "-";
            seatFlag = true;
        }
        if (seatFlag)
        {
            break;
        }
    }
    if (!seatFlag)
    { // verify the seat was assigned successfully, this check was moved outside the function
    }
    return seatCosts;
}
#endif