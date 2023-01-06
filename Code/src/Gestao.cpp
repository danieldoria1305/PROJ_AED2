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
        Airline al(AirlineCode,AirlineName,AirlineCallSign);
        it->second.addAirline(al);
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
            Country c(AirportCountry);
            countries_[AirportCountry]=c;
        }
        auto it=countries_.find(AirportCountry);
        Airport ap(AirportCode,AirportName,stof(AirportLongitude),stof(AirportLatitude));
        it->second.addAirport(ap,AirportCity);
        airports_[AirportCode]=ap;
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



