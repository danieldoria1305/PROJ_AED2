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
               "│   Best way to fly between airports     [11] │   Number of flights starting from a    [21] │\n"
               "│                                        [12] │   certain airport                           │\n"
               "│                                        [13] │   Number of destinies                  [22] │\n"
               "│                                        [14] │   Number of different airlines         [23] │\n"
               "╞═════════════════════════════════════════════╡   Number of different countries        [24] │\n"
               "│                Other operations             │   With a certain number of flights,    [25] │\n"
               "╞═════════════════════════════════════════════╡   how far can you go                        │\n"
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
            printNumberOfArrivals();
            break;
        case 23:
            printNumberOfAirlines();
            break;
        case 24:
            printNumberOfCountries();
            break;
        case 25:
            printHowFar();
            break;
        case 31:
            return false;
        default:
            cout << "Invalid Operation..." << endl;
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
    if(airportCode == "1") return;
    Airport airport;
    auto it=gestao.getAirports().find(airportCode);
    airport = it->second;
    cout << "╒═════════════════════════════════════════════╕\n"
            "│     The number of flights starting from     │\n";
    cout << "      " << airport.getName() << " is "
    << gestao.getFlights().getSources()[airport.getCode()].targets.size()<< "\n" <<
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
    set<string> airlines;
    auto aux = gestao.getFlights().getSources()[airportCode].targets;
    for(auto& i : aux) {
        airlines.insert(gestao.getAirlines()[i.airline].getName());
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "      The number of airlines : " << airlines.size() <<"\n";
    for(auto i : airlines) {
        cout << "╞═════════════════════════════════════════════╡\n"
                "    " << i << "\n";
    }
    cout << "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    cin.ignore();
}

void App::printHowFar(){
    int number;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│              Number of flights              │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the number of flights                │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >> number;
    string src;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│                Airport Code                 │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the airport code                     │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >> src;
    if(src == "1"){
        return;
    }
    cin.ignore();
    vector<pair<string,double>> v=gestao.getHowFar(number,src);
    cout << "╒═══════════════════════════════════════════════════════════════════════════════════════╕\n";
    for(auto a:v){
        cout <<" Airport: " << gestao.getAirports().find(a.first)->second.getName() <<
        "  Distance from one airport to another: "<< a.second << " km\n"
        "╞═══════════════════════════════════════════════════════════════════════════════════════╡\n";
    }
    cout << "│  Press enter to return                                                                │\n"
            "╘═══════════════════════════════════════════════════════════════════════════════════════╛\n"
            "                                                                                         \n";
    cin.ignore();
}

void App::printNumberOfArrivals() {
    string airportCode;
    cout <<  "╒═════════════════════════════════════════════╕\n"
             "│                Airport Code                 │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Write the airport code to get the number   │\n"
             "│ of arrivals                                 │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >> airportCode;
    cin.ignore();
    if(airportCode == "1") return;
    set<string> arrivals;
    auto aux = gestao.getFlights().getSources()[airportCode].targets;
    for(auto& i : aux) {
        arrivals.insert(gestao.getAirports().find(i.target)->second.getName());
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "  The number of destinies from "<< gestao.getAirports().find(airportCode)->second.getName()
            <<" : " << arrivals.size() <<"\n";
    for(auto i : arrivals) {
        cout << "╞═════════════════════════════════════════════╡\n"
                "   Airport: " << i << "\n";
    }
    cout << "╘═════════════════════════════════════════════╛\n"
    "                                               \n";
    cin.ignore();
}

void App::printNumberOfCountries() {
    string airportCode;
    cout <<  "╒══════════════════════════════════════════════╕\n"
             "│                Airport Code                  │\n"
             "╞══════════════════════════════════════════════╡\n"
             "│  Write the airport code to see the countries │\n"
             "│  you can fly to from this airport            │\n"
             "╞══════════════════════════════════════════════╡\n"
             "│  Return                                [1]   │\n"
             "╘══════════════════════════════════════════════╛\n"
             "                                                \n";
    cin >> airportCode;
    cin.ignore();
    if(airportCode == "1") return;
    set<string> countries;
    auto aux = gestao.getFlights().getSources()[airportCode].targets;
    for(auto& i : aux) {
        string country=gestao.getAirports().find(i.target)->second.getCountry();
        countries.insert(country);
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "      The number of countries : " << countries.size() <<"\n";
    for(auto i : countries) {
        cout << "╞═════════════════════════════════════════════╡\n"
                "   Country: " << i << "\n";
    }
    cout << "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    cin.ignore();
}