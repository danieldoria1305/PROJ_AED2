#include <iostream>
#include <algorithm>
#include <climits>
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
    cout << "╒══════════════════════════════════════════════════╤═════════════════════════════════════════════╕\n"
            "│              Flight Management                   │             Airports Information            │\n"
            "╞══════════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
            "│   Search best way to fly between airports   [11] │   Number of flights departing          [21] │\n"
            "│   Search best way to fly between cities     [12] │   Number of destinies                  [22] │\n"
            "│--------------------------------------------------│   Number of different airlines         [23] │\n"
            "│   Change airline preference list            [13] │   Number of different countries        [24] │\n"
            "╞══════════════════════════════════════════════════╡   With a certain number of flights,    [25] │\n"
            "│                Other operations                  │   how far can you go                        │\n"
            "╞══════════════════════════════════════════════════╡                                             │\n"
            "│  Exit                                       [31] │                                             │\n"
            "╘══════════════════════════════════════════════════╧═════════════════════════════════════════════╛\n"
            "                                                                                             \n";
    string operation;
    cin >> operation;
    cin.ignore();
    try {
        switch (stoi(operation)) {
            case 11: {
                printBestWayToFly();
                break;
            }
            case 12:
                printBestWayToFlyCities();
                break;
            case 13:
                printAirlinesMenu();
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
    }catch(std::invalid_argument){
        cout << "Invalid Operation..." << endl;
    }
    return true;
}

void App::printAirlinesMenu() {
    string action;
    cout <<  "╒═════════════════════════════════════════════╕\n";
    for(string s:airlines_){
        cout << "   "<< s << endl;
    }
    cout <<  "╞═════════════════════════════════════════════╡\n"
             "│  Add airline                           [3]  │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Clear airline preference list         [2]  │\n"
             "╞═════════════════════════════════════════════╡\n"
             "│  Return                                [1]  │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                               \n";
    cin >>action;
    cin.ignore();
    if(action == "1") return;
    if(action == "2"){
        airlines_.clear();
    }
    if(action == "3"){
        string airlineCode;
        cout << "Write airline code :" << endl;
        cin >> airlineCode;
        airlines_.insert(airlineCode);
    }
    printAirlinesMenu();
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
    vector<string> v;
    v=gestao.getDistance(source,target,airlines_);

    cout << "╒═════════════════════════════════════════════════════════════════╕\n"
            "│                            Flights 🌍                           │\n"
            "╞═════════════════════════════════════════════════════════════════╡\n";
    if(!v.empty()) {
        string prev=v[0];
        for (int i = 1; i < v.size(); i++) {
            cout << "  " << gestao.getAirports().find(prev)->second.getName()
                 << " 🛫    ---→   🛬 " << gestao.getAirports().find(v[i])->second.getName() << "\n";
            prev = v[i];
        }
    }
    cout << "╞═════════════════════════════════════════════════════════════════╡\n"
            "│  Press enter to return                                          │\n"
            "╘═════════════════════════════════════════════════════════════════╛\n"
            "                                                                   \n";
    cin.ignore();
}

void App::printBestWayToFlyCities(){
    string source,target;
    cout <<    "╒═════════════════════════════════════════════╕\n"
               "│                   Source                    │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Write the source city name                 │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Return                                [1]  │\n"
               "╘═════════════════════════════════════════════╛\n"
               "                                               \n";
    getline(cin, source);
    if(source=="1"){
        return ;
    }
    cout <<    "╒═════════════════════════════════════════════╕\n"
               "│                    Target                   │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Write the target city name                 │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Return                                [1]  │\n"
               "╘═════════════════════════════════════════════╛\n"
               "                                               \n";
    getline(cin,target);
    if(target=="1"){
        return ;
    }
    vector<vector<string>> v;
    int min=INT_MAX;
    for(string s:gestao.getCities().find(source)->second.getAirports()){
        for(string t:gestao.getCities().find(target)->second.getAirports()){
            vector<string> temp=gestao.getDistance(s,t,airlines_);
            if(temp.size()<min){
                min=temp.size();
                v.clear();
            }
            if(temp.size()==min){
                v.push_back(temp);
            }
        }
    }
    cout << "╒═════════════════════════════════════════════════════════════════╕\n"
            "│                            Flights 🌍                           │\n"
            "╞═════════════════════════════════════════════════════════════════╡\n";
    for(vector<string> vs:v) {
        if(!vs.empty()) {
            string prev = vs[0];
            for (int i = 1; i < vs.size(); i++) {
                cout << "  " << gestao.getAirports().find(prev)->second.getName()
                     << " 🛫    ---→   🛬 " << gestao.getAirports().find(vs[i])->second.getName() << "\n";
                prev = vs[i];
            }
            cout << "╞═════════════════════════════════════════════════════════════════╡\n";
        }
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