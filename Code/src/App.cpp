#include <iostream>
#include "../Include/App.h"


using namespace std;

void App::start() {
    gestao.readFileAirlines();
    gestao.readFileAirports();
    gestao.readFileFlights();
    while (true) {
        if(!printUserMenu()){
            break;
        }
    }
}

bool App::printUserMenu() {
    int operation;
    cout <<    "╒═════════════════════════════════════════════╤═════════════════════════════════════════════╕\n"
               "│             Request Management              │          Information About Flights          │\n"
               "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
               "│   Best way to fly between countries    [11] │   Number of flights stating from a     [21] │\n"
               "│                                        [12] │ certain departure airport                   │\n"
               "│                                        [13] │   Number of different airlines         [22] │\n"
               "│                                        [14] │   Number of arrivals                   [23] │\n"
               "╞═════════════════════════════════════════════╡   Number of different countries        [24] │\n"
               "│                Other operations             │   With a certain number of flights,    [25] │\n"
               "╞═════════════════════════════════════════════╡ how far can you go                          │\n"
               "│  Exit                                  [31] │                                             │\n"
               "╘═════════════════════════════════════════════╧═════════════════════════════════════════════╛\n"
               "                                                                                             \n";
    cin >> operation;
    cin.ignore();
    switch(operation){
        case 11:{
            break;
        }
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
        case 25:
            break;
        case 31:
            return false;
        default:
            cout << "Invalid Operation" << endl;
            return false;
    }
    return true;
}