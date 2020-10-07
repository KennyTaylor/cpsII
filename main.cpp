#include "Reservation.h"
#include "VehicleTypes.h"
#include <vector>
using namespace std;
int deleteReservation(int &reservationID, vector<Reservation> &reservations, vector<string> &names_db, vector<string> &points_db); // forward declaration of helper function, can go in helpers.h
void outputFile(vector<string> drivers, vector<string> names_db, vector<string> points_db, string filename);
vector<string> takeSeatIfFree(vector<string> seatCosts, string seat);

int main()
{
    // Reservation testRes("test player", "pickup", "red");
    // cout << testRes.getName() << " has a reservation in a " << testRes.getCarName() << " " << testRes.getCarType() << endl;

    // Pickup car2 = Pickup("Rob's", "pickup"); // idk what name and type are, just need to be something to distinguish the cars.
    // Vehicle car1 = Vehicle();
    // Compact car3 = Compact();
    // cout << car1.print() << endl;
    vector<Reservation> reservations, reservationsCopy;

    string name, lastname, type, color;
    int seat, reservationID;
    char selection;
    int i = 0;
    int count = 0;
    vector<string> names_db, drivers, seats_before;
    vector<string> points_db;
    fstream file;
    ofstream ofile;
    string word, word2, filename;
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
            space_char = word.find_last_of(" ");
            cut_name = word.substr(0, space_char);
            points = word.substr(space_char + 1);
            names_db.push_back(cut_name);
            points_db.push_back(points);
            cout << names_db.at(i) << " " << points_db.at(i) << endl;

            i += 1;
        }
        else
        {
            drivers.push_back(word);
            // do anything special with the drivers?
        }
        count += 1;
    }
    file.close();
    // assign drivers to their cars
    // Pickup pickup1 = Pickup(drivers.at(0), "Purple");
    // Compact compact1 = Compact(drivers.at(1), "Red");
    // Compact compact2 = Compact(drivers.at(2), "Blue");
    // Compact compact3 = Compact(drivers.at(3), "Yellow");
    // Sedan sedan1 = Sedan(drivers.at(4), "Blue");
    // Sedan sedan2 = Sedan(drivers.at(5), "Green");

    Pickup pickup1 = Pickup("Pickup", "Purple");
    Compact compact1 = Compact("Compact", "Red");
    Compact compact2 = Compact("Compact", "Blue");
    Compact compact3 = Compact("Compact", "Yellow");
    Sedan sedan1 = Sedan("Sedan", "Blue");
    Sedan sedan2 = Sedan("Sedan", "Green");

    ofstream p1, c1, c2, c3, s1, s2;

    bool quit = false;
    int playerIndex, tempPts, resID;
    bool foundFlag, noCredits;
    while (!quit)
    {
        cout << "make a selection: (C)reate, (M)odify, (D)elete, (P)rint, (Q)uit" << endl; // display all the user's options
        cin >> selection;                                                                  // user navigates the menu with
        switch (selection)
        {
        case 'c':
        case 'C':
            // create a reservation
            getline(cin, name); // flush cin or something
            cout << "enter name: " << endl;
            getline(cin, name);
            // cin >> name;
            // cin >> lastname;
            foundFlag = false;
            noCredits = false;
            for (int i = 0; i < names_db.size(); i++)
            {
                // cout << name << names_db.at(i) << endl; // debug print
                if (names_db.at(i) == name)
                {
                    cout << name << " has " << points_db.at(i) << " credits remaining." << endl;
                    if (points_db.at(i) == "0")
                    {
                        noCredits = true;
                    }
                    playerIndex = i;
                    foundFlag = true;
                    break; // break the for loop, since we found the name
                }
            }
            if (noCredits)
            {
                cout << "Error: you have no credits" << endl;
                break;
            }
            if (!foundFlag)
            {
                cout << "Error, invalid name" << endl;
                break; // break the switch statement
            }

            cout << pickup1.print() << endl
                 << compact1.print() << endl
                 << compact2.print() << endl
                 << compact3.print() << endl
                 << sedan1.print() << endl
                 << sedan2.print() << endl;
            // TODO: make the menu being printed here match the spec, making use of vehicle.print()

            // TODO: big ass if statement chain like if the user says they want a seat in a compact that costs 2 check a compact and see if it has a 2 cost seat available etc etc

            // make sure they don't already have a reservation, then push their reservation
            //  also make sure they have enough points for the reservation they are making
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
            // if they don't already have one, and they have enough points to pay for it, add them

            if (foundFlag)
            { // duplicate reservation
                break;
            }
            else
            {
                // cout << points_db.at(playerIndex) << endl
                //      << points_db.at(playerIndex).c_str() << endl;
                tempPts = stoi(points_db.at(playerIndex).c_str());
                // cout << tempPts << endl;
                // cout << "enter car type: ";
                // cin >> type;
                cout << "enter desired seat by cost: ";
                cin >> seat;
            }
            if (tempPts >= seat) // no duplicate and enough to pay
            {
                // TODO: two different ways of specifying which seat
                cout << "which type of reservation do you want?\noptions: (c)ategory, (s)eat" << endl;
                cin >> selection;
                while (selection != 'c' and selection != 's' and selection != 'C' and selection != 'S')
                {
                    cout << "choose (c)ategory or (s)eat" << endl;
                    cin >> selection;
                }

                // cout << "enter seat cost";
                // getline(cin, word2);
                if (selection == 'c')
                {
                    cout << "enter car type ex: Purple Pickup" << endl;
                    word = "invalid";
                    getline(cin, word); // flush or whatever
                    getline(cin, type);
                    // check each car

                    if (type == "Purple Pickup")
                    {
                        seats_before = pickup1.getSeatCosts();
                        pickup1.setSeatCosts(takeSeatIfFree(pickup1.getSeatCosts(), to_string(seat)));
                        if (seats_before == pickup1.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Purple Pickup seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Red Compact")
                    {
                        seats_before = compact1.getSeatCosts();
                        compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                        if (seats_before == compact1.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Red Compact seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Blue Compact")
                    {
                        seats_before = compact2.getSeatCosts();
                        compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                        if (seats_before == compact2.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Blue Compact seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Yellow Compact")
                    {
                        seats_before = compact3.getSeatCosts();
                        compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                        if (seats_before == compact3.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Yellow Compact seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Blue Sedan")
                    {
                        seats_before = sedan1.getSeatCosts();
                        sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                        if (seats_before == sedan1.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Blue Sedan seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Green Sedan")
                    {
                        seats_before = sedan2.getSeatCosts();
                        sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                        if (seats_before == sedan2.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Green Sedan seat not available, try again" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << "error, invalid car type, should match [Color] [Vehicle_type] ex: Blue Sedan" << endl;
                        break;
                    }
                }
                else // select by seat
                {
                    if (seat == 5)
                    {
                        if (pickup1.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            pickup1.setSeatCosts(takeSeatIfFree(pickup1.getSeatCosts(), to_string(seat)));
                            type = "Purple Pickup";
                        }
                        else if (compact1.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                            type = "Red Compact";
                        }
                        else if (compact2.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                            type = "Blue Compact";
                        }
                        else if (compact3.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                            type = "Yellow Compact";
                        }
                        else if (sedan1.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else
                        {
                            cout << "that seat selection is not available in any cars" << endl;
                            break;
                        }
                    }
                    else if (seat == 3)
                    {
                        if (compact1.getSeatCosts().at(2) == "3") // verify that compact has that seat available
                        {
                            compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                            type = "Red Compact";
                        }
                        else if (compact1.getSeatCosts().at(3) == "3") // verify that compact has that seat available
                        {
                            compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                            type = "Red Compact";
                        }
                        else if (compact2.getSeatCosts().at(2) == "3") // verify that compact has that seat available
                        {
                            compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                            type = "Blue Compact";
                        }
                        else if (compact2.getSeatCosts().at(3) == "3") // verify that compact has that seat available
                        {
                            compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                            type = "Blue Compact";
                        }
                        else if (compact3.getSeatCosts().at(2) == "3") // verify that compact has that seat available
                        {
                            compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                            type = "Yellow Compact";
                        }
                        else if (compact3.getSeatCosts().at(3) == "3") // verify that compact has that seat available
                        {
                            compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                            type = "Yellow Compact";
                        }
                        else
                        {
                            cout << "compact window seats not free in any car." << endl;
                            break;
                        }
                    }
                    else if (seat == 2)
                    {
                        if (sedan1.getSeatCosts().at(3) == "1") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(3) == "1") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else
                        {
                            cout << "Sedan middle seat is not available in any cars" << endl;
                            break;
                        }
                    }
                    else if (seat == 1)
                    {
                        if (sedan1.getSeatCosts().at(2) == "2") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan1.getSeatCosts().at(4) == "2") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(2) == "2") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(4) == "2") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else
                        {
                            cout << "Sedan window seat is not available in any cars" << endl;
                            break;
                        }
                    }

                    //     pickup1.print() << endl
                    //  << compact1.print() << endl
                    //  << compact2.print() << endl
                    //  << compact3.print() << endl
                    //  << sedan1.print() << endl
                    //  << sedan2
                }
                cout << "reservation created for " << name << " in " << type << ", cost " << seat << " credits" << endl;
                points_db.at(playerIndex) = to_string(tempPts - seat);                      // pay for it
                reservations.push_back(Reservation(string(name), string(type), int(seat))); // add to list
            }
            else
            {
                cout << "Error: not enought points to create reservation." << endl;
                cout << "You have: " << points_db.at(playerIndex) << " points." << endl;
                break;
            }
            break; // end of create reservation
        case 'm':
        case 'M':
            // modify a reservation
            cout << "Modify was selected." << endl;
            // cout << "Reservations:" << endl;
            // for (int i = 0; i < reservations.size(); i++)
            // {
            //     cout << i << ": " << reservations[i].print() << endl;
            // }
            // deleteReservation(resID, reservations, names_db, points_db);
            // modify -> create
            getline(cin, name); // flush cin or something /////////////////////////////////////if modify isnt working test this
            cout << "enter new reservation info" << endl;
            // create a reservation
            cout << "enter name: " << endl;
            getline(cin, name);
            // cin >> name;
            // cin >> lastname;
            foundFlag = false;
            noCredits = false;
            for (int i = 0; i < names_db.size(); i++)
            {
                // cout << name << names_db.at(i) << endl; // debug print
                if (names_db.at(i) == name)
                {
                    cout << name << " has " << points_db.at(i) << " credits remaining." << endl;
                    if (points_db.at(i) == "0")
                    {
                        noCredits = true;
                    }
                    playerIndex = i;
                    foundFlag = true;
                    break; // break the for loop, since we found the name
                }
            }
            if (noCredits)
            {
                cout << "Error: you have no credits" << endl;
                break;
            }
            if (!foundFlag)
            {
                cout << "Error, invalid name" << endl;
                break; // break the switch statement
            }

            cout << pickup1.print() << endl
                 << compact1.print() << endl
                 << compact2.print() << endl
                 << compact3.print() << endl
                 << sedan1.print() << endl
                 << sedan2.print() << endl;
            // TODO: make the menu being printed here match the spec, making use of vehicle.print()

            // TODO: big ass if statement chain like if the user says they want a seat in a compact that costs 2 check a compact and see if it has a 2 cost seat available etc etc

            // make sure they don't already have a reservation, then push their reservation
            //  also make sure they have enough points for the reservation they are making
            foundFlag = false;
            for (int i = 0; i < reservations.size(); i++)
            {
                if (foundFlag)
                {
                    break;
                }
                if (reservations.at(i).getName() == name)
                {
                    cout << "Modifying " << name << "'s reservation" << endl;
                    foundFlag = true;
                }
            }
            // if they don't already have one, and they have enough points to pay for it, add them

            if (!foundFlag)
            { // no reservation for that person to modify
                cout << "you don't have a reservation to modify. Choose (C)reate to make one." << endl;
                break;
            }
            else
            {
                // cout << points_db.at(playerIndex) << endl
                //      << points_db.at(playerIndex).c_str() << endl;
                tempPts = stoi(points_db.at(playerIndex).c_str());
                // cout << tempPts << endl;
                // cout << "enter car type: ";
                // cin >> type;
                cout << "enter desired seat by cost: ";
                cin >> seat;
            }
            if (tempPts >= seat) // no duplicate and enough to pay
            {
                // TODO: two different ways of specifying which seat
                cout << "which type of reservation do you want?\noptions: (c)ategory, (s)eat" << endl;
                cin >> selection;
                while (selection != 'c' and selection != 's' and selection != 'C' and selection != 'S')
                {
                    cout << "choose (c)ategory or (s)eat" << endl;
                    cin >> selection;
                }

                // cout << "enter seat cost";
                // getline(cin, word2);
                if (selection == 'c')
                {
                    cout << "enter car type ex: Purple Pickup" << endl;
                    word = "invalid";
                    getline(cin, word); // flush or whatever
                    getline(cin, type);
                    // check each car

                    if (type == "Purple Pickup")
                    {
                        seats_before = pickup1.getSeatCosts();
                        pickup1.setSeatCosts(takeSeatIfFree(pickup1.getSeatCosts(), to_string(seat)));
                        if (seats_before == pickup1.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Purple Pickup seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Red Compact")
                    {
                        seats_before = compact1.getSeatCosts();
                        compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                        if (seats_before == compact1.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Red Compact seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Blue Compact")
                    {
                        seats_before = compact2.getSeatCosts();
                        compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                        if (seats_before == compact2.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Blue Compact seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Yellow Compact")
                    {
                        seats_before = compact3.getSeatCosts();
                        compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                        if (seats_before == compact3.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Yellow Compact seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Blue Sedan")
                    {
                        seats_before = sedan1.getSeatCosts();
                        sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                        if (seats_before == sedan1.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Blue Sedan seat not available, try again" << endl;
                            break;
                        }
                    }
                    else if (type == "Green Sedan")
                    {
                        seats_before = sedan2.getSeatCosts();
                        sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                        if (seats_before == sedan2.getSeatCosts())
                        {
                            // seat was not available
                            cout << "Green Sedan seat not available, try again" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << "error, invalid car type, should match [Color] [Vehicle_type] ex: Blue Sedan" << endl;
                        break;
                    }
                }
                else // select by seat
                {
                    if (seat == 5)
                    {
                        if (pickup1.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            pickup1.setSeatCosts(takeSeatIfFree(pickup1.getSeatCosts(), to_string(seat)));
                            type = "Purple Pickup";
                        }
                        else if (compact1.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                            type = "Red Compact";
                        }
                        else if (compact2.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                            type = "Blue Compact";
                        }
                        else if (compact3.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                            type = "Yellow Compact";
                        }
                        else if (sedan1.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(1) == "5") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else
                        {
                            cout << "that seat selection is not available in any cars" << endl;
                            break;
                        }
                    }
                    else if (seat == 3)
                    {
                        if (compact1.getSeatCosts().at(2) == "3") // verify that compact has that seat available
                        {
                            compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                            type = "Red Compact";
                        }
                        else if (compact1.getSeatCosts().at(3) == "3") // verify that compact has that seat available
                        {
                            compact1.setSeatCosts(takeSeatIfFree(compact1.getSeatCosts(), to_string(seat)));
                            type = "Red Compact";
                        }
                        else if (compact2.getSeatCosts().at(2) == "3") // verify that compact has that seat available
                        {
                            compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                            type = "Blue Compact";
                        }
                        else if (compact2.getSeatCosts().at(3) == "3") // verify that compact has that seat available
                        {
                            compact2.setSeatCosts(takeSeatIfFree(compact2.getSeatCosts(), to_string(seat)));
                            type = "Blue Compact";
                        }
                        else if (compact3.getSeatCosts().at(2) == "3") // verify that compact has that seat available
                        {
                            compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                            type = "Yellow Compact";
                        }
                        else if (compact3.getSeatCosts().at(3) == "3") // verify that compact has that seat available
                        {
                            compact3.setSeatCosts(takeSeatIfFree(compact3.getSeatCosts(), to_string(seat)));
                            type = "Yellow Compact";
                        }
                        else
                        {
                            cout << "compact window seats not free in any car." << endl;
                            break;
                        }
                    }
                    else if (seat == 2)
                    {
                        if (sedan1.getSeatCosts().at(3) == "1") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(3) == "1") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else
                        {
                            cout << "Sedan middle seat is not available in any cars" << endl;
                            break;
                        }
                    }
                    else if (seat == 1)
                    {
                        if (sedan1.getSeatCosts().at(2) == "2") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan1.getSeatCosts().at(4) == "2") // verify that pickup has that seat available
                        {
                            sedan1.setSeatCosts(takeSeatIfFree(sedan1.getSeatCosts(), to_string(seat)));
                            type = "Blue Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(2) == "2") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else if (sedan2.getSeatCosts().at(4) == "2") // verify that pickup has that seat available
                        {
                            sedan2.setSeatCosts(takeSeatIfFree(sedan2.getSeatCosts(), to_string(seat)));
                            type = "Green Sedan";
                        }
                        else
                        {
                            cout << "Sedan window seat is not available in any cars" << endl;
                            break;
                        }
                    }

                    //     pickup1.print() << endl
                    //  << compact1.print() << endl
                    //  << compact2.print() << endl
                    //  << compact3.print() << endl
                    //  << sedan1.print() << endl
                    //  << sedan2
                }
                cout << "Reservations:" << endl;
                for (int i = 0; i < reservations.size(); i++)
                {
                    cout << i << ": " << reservations[i].print() << endl;
                }
                deleteReservation(resID, reservations, names_db, points_db);

                cout << "reservation created for " << name << " in " << type << ", cost " << seat << " credits" << endl;
                points_db.at(playerIndex) = to_string(tempPts - seat);                      // pay for it
                reservations.push_back(Reservation(string(name), string(type), int(seat))); // add to list
            }
            else
            {
                cout << "Error: not enought points to create reservation." << endl;
                cout << "You have: " << points_db.at(playerIndex) << " points." << endl;
                break;
            }
            break; // end of modify reservation
        case 'd':
        case 'D':
            // delete a reservation
            deleteReservation(reservationID, reservations, names_db, points_db); // helper function at the bottom of main, could go in helpers.h or similar
            break;                                                               // end of delete reservation
        case 'p':
        case 'P':
            cout << "select a car by type" << endl;
            cout << pickup1.print() << endl
                 << compact1.print() << endl
                 << compact2.print() << endl
                 << compact3.print() << endl
                 << sedan1.print() << endl
                 << sedan2.print() << endl;
            getline(cin, word); // flush cin
            getline(cin, word);

            break;
        case 'a':
        case 'A': // admin
            // print the reservations
            cout << "enter password" << endl;
            getline(cin, word); // flush cin
            getline(cin, word);
            if (word == "password")
            {
                ofile.open("all_reservations.txt");
                ofile << pickup1.getType() << " " << pickup1.getName() << endl;
                reservationsCopy = reservations;
                ofile << "driver: " << drivers[0] << endl;
                for (int i = 1; i < pickup1.getSeatCosts().size(); i++) // {"-","5"}
                {
                    foundFlag = false;
                    for (int resIndex = 0; resIndex < reservationsCopy.size(); resIndex++)
                    {
                        cout << reservationsCopy.at(resIndex).getName() << endl;
                        cout << reservationsCopy.at(resIndex).getCarType() << endl;
                        cout << pickup1.getType() << endl;
                        cout << Pickup().getSeatCosts()[i] << endl;
                        cout << reservationsCopy.at(resIndex).getCredits() << endl;
                        if (reservationsCopy.at(resIndex).getCarType() == (pickup1.getType() + " " + pickup1.getName()) and reservationsCopy.at(resIndex).getCredits() == stoi(Pickup().getSeatCosts()[i]) and (pickup1.getSeatCosts()[i] == "-"))
                        {
                            ofile << reservationsCopy[resIndex].getName() << ": " << reservationsCopy[resIndex].getCredits() << endl;
                        }
                    }

                    if (pickup1.getSeatCosts().at(i) != "-")
                    {
                        ofile << "Unassigned: " << pickup1.getSeatCosts().at(i) << endl;
                    }
                }
                // compact1
                ofile << compact1.getType() << " " << compact1.getName() << endl;
                reservationsCopy = reservations;
                ofile << "driver: " << drivers[0] << endl;
                for (int i = 1; i < compact1.getSeatCosts().size(); i++) // {"-","5"}
                {
                    foundFlag = false;
                    for (int resIndex = 0; resIndex < reservationsCopy.size(); resIndex++)
                    {
                        cout << reservationsCopy.at(resIndex).getName() << endl;
                        cout << reservationsCopy.at(resIndex).getCarType() << endl;
                        cout << compact1.getType() << endl;
                        cout << Compact().getSeatCosts()[i] << endl;
                        cout << reservationsCopy.at(resIndex).getCredits() << endl;
                        if (reservationsCopy.at(resIndex).getCarType() == (compact1.getType() + " " + compact1.getName()) and reservationsCopy.at(resIndex).getCredits() == stoi(Compact().getSeatCosts()[i]) and (compact1.getSeatCosts()[i] == "-"))
                        {
                            ofile << reservationsCopy[resIndex].getName() << ": " << reservationsCopy[resIndex].getCredits() << endl;
                        }
                    }

                    if (compact1.getSeatCosts().at(i) != "-")
                    {
                        ofile << "Unassigned: " << compact1.getSeatCosts().at(i) << endl;
                    }
                }
                // compact2
                ofile << compact2.getType() << " " << compact2.getName() << endl;
                reservationsCopy = reservations;
                ofile << "driver: " << drivers[0] << endl;
                for (int i = 1; i < compact2.getSeatCosts().size(); i++) // {"-","5"}
                {
                    foundFlag = false;
                    for (int resIndex = 0; resIndex < reservationsCopy.size(); resIndex++)
                    {
                        cout << reservationsCopy.at(resIndex).getName() << endl;
                        cout << reservationsCopy.at(resIndex).getCarType() << endl;
                        cout << compact2.getType() << endl;
                        cout << Compact().getSeatCosts()[i] << endl;
                        cout << reservationsCopy.at(resIndex).getCredits() << endl;
                        if (reservationsCopy.at(resIndex).getCarType() == (compact2.getType() + " " + compact2.getName()) and reservationsCopy.at(resIndex).getCredits() == stoi(Compact().getSeatCosts()[i]) and (compact2.getSeatCosts()[i] == "-"))
                        {
                            ofile << reservationsCopy[resIndex].getName() << ": " << reservationsCopy[resIndex].getCredits() << endl;
                        }
                    }

                    if (compact2.getSeatCosts().at(i) != "-")
                    {
                        ofile << "Unassigned: " << compact2.getSeatCosts().at(i) << endl;
                    }
                }
                // compact3
                ofile << compact3.getType() << " " << compact3.getName() << endl;
                reservationsCopy = reservations;
                ofile << "driver: " << drivers[0] << endl;
                for (int i = 1; i < compact3.getSeatCosts().size(); i++) // {"-","5"}
                {
                    foundFlag = false;
                    for (int resIndex = 0; resIndex < reservationsCopy.size(); resIndex++)
                    {
                        cout << reservationsCopy.at(resIndex).getName() << endl;
                        cout << reservationsCopy.at(resIndex).getCarType() << endl;
                        cout << compact3.getType() << endl;
                        cout << Compact().getSeatCosts()[i] << endl;
                        cout << reservationsCopy.at(resIndex).getCredits() << endl;
                        if (reservationsCopy.at(resIndex).getCarType() == (compact3.getType() + " " + compact3.getName()) and reservationsCopy.at(resIndex).getCredits() == stoi(Compact().getSeatCosts()[i]) and (compact3.getSeatCosts()[i] == "-"))
                        {
                            ofile << reservationsCopy[resIndex].getName() << ": " << reservationsCopy[resIndex].getCredits() << endl;
                        }
                    }

                    if (compact3.getSeatCosts().at(i) != "-")
                    {
                        ofile << "Unassigned: " << compact3.getSeatCosts().at(i) << endl;
                    }
                }
                // sedan1
                ofile << sedan1.getType() << " " << sedan1.getName() << endl;
                reservationsCopy = reservations;
                ofile << "driver: " << drivers[0] << endl;
                for (int i = 1; i < sedan1.getSeatCosts().size(); i++) // {"-","5"}
                {
                    foundFlag = false;
                    for (int resIndex = 0; resIndex < reservationsCopy.size(); resIndex++)
                    {
                        cout << reservationsCopy.at(resIndex).getName() << endl;
                        cout << reservationsCopy.at(resIndex).getCarType() << endl;
                        cout << sedan1.getType() << endl;
                        cout << Sedan().getSeatCosts()[i] << endl;
                        cout << reservationsCopy.at(resIndex).getCredits() << endl;
                        if (reservationsCopy.at(resIndex).getCarType() == (sedan1.getType() + " " + sedan1.getName()) and reservationsCopy.at(resIndex).getCredits() == stoi(Sedan().getSeatCosts()[i]) and (sedan1.getSeatCosts()[i] == "-"))
                        {
                            ofile << reservationsCopy[resIndex].getName() << ": " << reservationsCopy[resIndex].getCredits() << endl;
                        }
                    }

                    if (sedan1.getSeatCosts().at(i) != "-")
                    {
                        ofile << "Unassigned: " << sedan1.getSeatCosts().at(i) << endl;
                    }
                }
                // sedan2
                ofile << sedan2.getType() << " " << sedan2.getName() << endl;
                reservationsCopy = reservations;
                ofile << "driver: " << drivers[0] << endl;
                for (int i = 1; i < sedan2.getSeatCosts().size(); i++) // {"-","5"}
                {
                    foundFlag = false;
                    for (int resIndex = 0; resIndex < reservationsCopy.size(); resIndex++)
                    {
                        cout << reservationsCopy.at(resIndex).getName() << endl;
                        cout << reservationsCopy.at(resIndex).getCarType() << endl;
                        cout << sedan2.getType() << endl;
                        cout << Sedan().getSeatCosts()[i] << endl;
                        cout << reservationsCopy.at(resIndex).getCredits() << endl;
                        if (reservationsCopy.at(resIndex).getCarType() == (sedan2.getType() + " " + sedan2.getName()) and reservationsCopy.at(resIndex).getCredits() == stoi(Sedan().getSeatCosts()[i]) and (sedan2.getSeatCosts()[i] == "-"))
                        {
                            ofile << reservationsCopy[resIndex].getName() << ": " << reservationsCopy[resIndex].getCredits() << endl;
                        }
                    }

                    if (sedan2.getSeatCosts().at(i) != "-")
                    {
                        ofile << "Unassigned: " << sedan2.getSeatCosts().at(i) << endl;
                    }
                }
                // pickup1.print() << endl
                //  << compact1.print() << endl
                //  << compact2.print() << endl
                //  << compact3.print() << endl
                //  << sedan1.print() << endl
                //  << sedan2
            }
            else
            {
                cout << "incorrect password" << endl;
            }
            ofile.close();
            break;
        case 'q':
        case 'Q':
            cout << "quitting";
            outputFile(drivers, names_db, points_db, filename);

            quit = true;
            break;
        default:
            cout << "enter a valid option" << endl;
            break;
        };
    }

    return 0;
}

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