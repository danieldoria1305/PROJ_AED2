#include <iostream>
#include <algorithm>
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
               "│              Flight Management              │          Information About Airports         │\n"
               "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
               "│   Best way to fly between airports     [11] │   Number of flights stating from a     [21] │\n"
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
            printBestWayToFly();
            break;
        }
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 21:
            printNumberOfFlights();
            break;
        case 22:
            printNumberOfAirlines();
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

void App::printNumberOfFlights() {
    string airportCode;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│                Airport Code                 │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the airport code to see the number   │\n"
             "│ of flights                                  │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >> airportCode;
    cin.ignore();
    if(airportCode == "1"){
        return;
    }
    Airport airport;
    auto it=gestao.getAirports().find(airportCode);
    airport = it->second;
    cout << "╒═════════════════════════════════════════════╕\n"
            "│     The number of flights starting from     │\n";
    cout << "    " << airport.getCode() << " is " << gestao.getFlights().getSources()[airport.getCode()].targets.size() << "\n" <<
            "╘═════════════════════════════════════════════╛\n";
    cin.ignore();
}

void App::printBestWayToFly(){
    string source,target;
    cout <<    "╒═════════════════════════════════════════════╕\n"
               "│                   Source                    │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Write the source airport code              │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Return                                [1]  │\n"
               "╘═════════════════════════════════════════════╛\n"
               "                                               \n";
    cin >> source;
    if(source=="1"){
        return ;
    }
    cout <<    "╒═════════════════════════════════════════════╕\n"
               "│                    Target                   │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Write the target airport code              │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Return                                [1]  │\n"
               "╘═════════════════════════════════════════════╛\n"
               "                                               \n";
    cin >> target;
    if(target=="1"){
        return ;
    }
    cin.ignore();
    vector<string> v=gestao.getDistance(source,target);
    string prev=v[0];
    cout << "╒═════════════════════════════════════════════════════════════════╕\n"
            "│                            Flights 🌍                           │\n"
            "╞═════════════════════════════════════════════════════════════════╡\n";
    for(int i=1;i<v.size();i++){
        cout << "  " << gestao.getAirports().find(prev)->second.getName()
        << " 🛫    ---→   🛬 " << gestao.getAirports().find(v[i])->second.getName() << "\n"
             "╞═════════════════════════════════════════════════════════════════╡\n";
        prev=v[i];
    }
    cout << "│  Press enter to return                                          │\n"
            "╘═════════════════════════════════════════════════════════════════╛\n"
            "                                                                   \n";
    cin.ignore();
}

void App::printNumberOfAirlines() {
    string airportCode;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│                Airport Code                 │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the airport code to see the number   │\n"
             "│ of flights                                  │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >> airportCode;
    cin.ignore();
    if(airportCode == "1"){
        return;
    }
    Airport airport;
    auto it = gestao.getAirports().find(airportCode);
    airport = it->second;
    vector<string> airlines;
    int count = 0;
    auto aux = gestao.getFlights().getSources()[airport.getCode()].targets;
    for(auto& i : aux) {
        if(find(airlines.begin(), airlines.end(), gestao.getAirlines()[i.airline].getName()) == airlines.end()) {
            count++;
            airlines.push_back(gestao.getAirlines()[i.airline].getName());
        }
    }
    sort(airlines.begin(), airlines.end());
    cout << "╒═════════════════════════════════════════════╕\n"
            "      The number of airlines : " << count <<"\n";
    for(auto i : airlines) {
        cout << "╞═════════════════════════════════════════════╡\n"
                "    " << i << "\n";
    }
    cout << "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    cin.ignore();
}