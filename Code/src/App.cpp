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
               "│                                             │                                             │\n"
               "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
               "│                                        [11] │                                        [21] │\n"
               "│                                        [12] │                                        [22] │\n"
               "│                                        [13] │                                        [23] │\n"
               "╞═════════════════════════════════════════════╡                                        [24] │\n"
               "│                Other operations             │                                        [25] │\n"
               "╞═════════════════════════════════════════════╡                                             │\n"
               "│  Exit                                  [31] │                                             │\n"
               "╘═════════════════════════════════════════════╧═════════════════════════════════════════════╛\n"
               "                                                                                             \n";
    cin >> operation;
    cin.ignore();
    switch(operation){
        case 11:
            break;
        case 12:
            break;
        case 13:
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
    }
    return true;
}