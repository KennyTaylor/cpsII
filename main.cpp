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
    file.seek
    while (getline(filename, word)) {
        if (count >= 6) {
            int space_char;
            string points, cut_name;
            names_array[i] = word;
            space_char = word.find_last_of(" ");
            cut_name = word.substr(0, space_char);
            points = word.substr(space_char);
            names_array[i] = cut_name;
            points_array[i] = points;
            i += 1;
        }
        count += 1;
    }
    // End From today
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
            if (word == name) {
                Reservation Reservation1(name, type, seat); 
            }
            else {
                cout << "Name not found." << endl;
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
