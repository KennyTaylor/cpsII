#include "Reservation.h"
#include <vector>
using namespace std;

int main()
{
    Reservation testRes("test player", "pickup", "red"); // Create an object of MyClass

    cout << testRes.getName() << " has a reservation in a " << testRes.getCarName() << " " << testRes.getCarType() << endl;

    vector<Reservation> reservations = {testRes};

    string name, type, color;
    int seat, reservationID;
    char selection;

    bool quit = false;
    while (!quit)
    {
        cout << "menu" << endl; // display all the user's options
        cin >> selection;       // user navigates the menu with
        switch (selection)
        {
        case 'c':
        case 'C':
            // create a reservation
            cout << "enter name: ";
            cin >> name;
            cout << "enter car type: ";
            cin >> type;
            cout << "enter seat by cost: ";
            cin >> seat;
            cout << "reservation created for " << name << " in " << type << ", cost " << seat << " credits" << endl;
            // From today
            fstream file;
            string word, filename;

            filename = "quidditch_team.dat";
            file.open(filename.c_str());
            while (file >> word)
            {
                if (word == name) {
                    C.Reservation(name, type, seat); // I'm not that fimiliar with "case" so I don't know if I need to add the "C." there, if not, just delete it.
                }
            }
            // End of From today
            break;
        case 'm':
        case 'M':
            // modify a reservation
            break;
        case 'd':
        case 'D':
            // delete a reservation
            cout << "enter reservation ID to delete: ";
            cin >> reservationID;
            while (reservationID < 0 && reservationID > 17)
            {
                cout << "enter a valid ID between 0 and 17: ";
                cin >> reservationID;
            }
            reservations[reservationID].remove();
            cout << "reservation " << reservationID << " was deleted" << endl;
            break;
        case 'p':
        case 'P':
            // print the reservations
            for (int i = 0; i < reservations.size(); i++)
            {
                cout << reservations[i].print() << endl;
            }
            break;
        default:
            cout << "enter a valid option" << endl;
            break;
        };
    }

    return 0;
}
