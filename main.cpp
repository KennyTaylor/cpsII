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
    // From today
    int i = 0;
    int count = 0;
    string names_array[18];
    string points_array[18];
    fstream file;
    string word, filename;
    int points_left;
    filename = "quidditch_team.dat";
    file.open(filename.c_str());
    // file.seek

    // read player names and points from the file once, keep them in memory
    while (getline(file, word))
    {
        if (count >= 6)
        {
            int space_char;
            string points, cut_name;
            names_array[i] = word;
            space_char = word.find_last_of(" ");
            cut_name = word.substr(0, space_char);
            points = word.substr(space_char);
            names_array[i] = cut_name;
            points_array[i] = points;
            i += 1;
            // cout << cut_name << endl; // didnt mean to commit this test print whoops
        }
        count += 1;
    }
    // End From today
    bool quit = false;
    bool foundFlag;
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

            // make sure they don't already have a reservation, then push their reservation
            // TODO: also make sure they have enough points for the reservation they are making
            foundFlag = false;
            for (int i = 0; i < reservations.size(); i++)
            {
                if (foundFlag)
                {
                    break;
                }
                if (reservations.at(i).getName() == name)
                {
                    cout << "You already have a reservation. Choose modify to change it." << endl;
                    foundFlag = true;
                }
            }
            // if they don't already have one, add them
            if (!foundFlag)
            {
                cout << "creating your reservation" << endl;
                reservations.push_back(Reservation(string(name), string(type), int(seat)));
            }

            break; // end of create reservation
        case 'm':
        case 'M':
            // modify a reservation
            cout << "modify not implemented. will reuse most of create for it " << endl;
            break; // end of modify reservation
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
            break; // end of delete reservation
        case 'p':
        case 'P':
            // print the reservations
            for (int i = 0; i < reservations.size(); i++)
            {
                cout << reservations[i].print() << endl;
            }
            break;
        case 'q':
        case 'Q':
            cout << "quitting";
            quit = true;
        default:
            cout << "enter a valid option" << endl;
            break;
        };
    }

    return 0;
}
