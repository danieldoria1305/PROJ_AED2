#include "../Include/Gestao.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>

vector<string> Gestao::getDistance(string a, string b) {
    return flights_.dijkstra(a,b);
}

vector<pair<string, double>> Gestao::getHowFar(int i, string src){
    return flights_.howFar(i,src);
}

void Gestao::readFileAirlines() {  // INCOMPLETE
    std::ifstream airlines;
    airlines.open("../Code/dataset/airlines.csv");
    string code="", name="", callsign="", country="";
    string line;
    getline(airlines, line); // Skip the first line
    while (getline(airlines, line)) {
        stringstream inputString(line);
        string AirlineCode, AirlineName, AirlineCallSign, AirlineCountry;
        getline(inputString, AirlineCode, ',');
        getline(inputString, AirlineName, ',');
        getline(inputString, AirlineCallSign, ',');
        getline(inputString, AirlineCountry, '\r');
        if(countries_.find(AirlineCountry)==countries_.end()){
            Country c(AirlineCountry);
            countries_[AirlineCountry]=c;
        }
        auto it=countries_.find(AirlineCountry);
        Airline al(AirlineCode,AirlineName,AirlineCallSign,AirlineCountry);
        airlines_[AirlineCode]=al;
        it->second.addAirline(AirlineCode);
    }
}

void Gestao::readFileAirports() {  // INCOMPLETE
    std::ifstream airports;
    airports.open("../Code/dataset/airports.csv");
    string code="", name="", city="", country="", latitude="", longitude="";
    string line;
    getline(airports, line); // Skip the first line
    while (getline(airports, line)) {
        stringstream inputString(line);
        string AirportCode, AirportName, AirportCity, AirportCountry, AirportLatitude, AirportLongitude;
        getline(inputString, AirportCode, ',');
        getline(inputString, AirportName, ',');
        getline(inputString, AirportCity, ',');
        getline(inputString, AirportCountry, ',');
        getline(inputString, AirportLatitude, ',');
        getline(inputString, AirportLongitude, '\r');
        if(countries_.find(AirportCountry)==countries_.end()){
            Country coutry_(AirportCountry);
            countries_[AirportCountry]=coutry_;
        }
        auto it=countries_.find(AirportCountry);
        Airport ap(AirportCode,AirportName,AirportCity,AirportCountry,stof(AirportLongitude),stof(AirportLatitude));
        it->second.addCity(AirportCity);
        airports_[AirportCode]=ap;
        if(cities_.find(AirportCity)==cities_.end()){
            City city(AirportCity);
            cities_[AirportCity]=city;
        }
        auto itc=cities_.find(AirportCity);
        itc->second.addAirport(AirportCode);
    }
}

void Gestao::readFileFlights() {  // INCOMPLETE
    std::ifstream flights;
    flights.open("../Code/dataset/flights.csv");
    string line;
    getline(flights, line); // Skip the first line
    while (getline(flights, line)) {
        stringstream inputString(line);
        string FlightSource, FlightTarget, FlightAirline;
        getline(inputString, FlightSource, ',');
        getline(inputString, FlightTarget, ',');
        getline(inputString, FlightAirline, '\r');
        auto source=airports_.find(FlightSource);
        auto target=airports_.find(FlightTarget);
        flights_.addEdge(source->second,target->second,FlightAirline);
    }
}

M_airport Gestao::getAirports() const {
    return airports_;
}

Flights Gestao::getFlights() const {
    return flights_;
}

M_airline Gestao::getAirlines() const {
    return airlines_;
}

M_country Gestao::getCountries() const {
    return countries_;
}



