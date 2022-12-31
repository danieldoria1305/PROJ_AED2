#include "../Include/Gestao.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

void Gestao::readFileAirlines() {  // INCOMPLETE
    std::ifstream airlines;
    airlines.open("../dataset/airlines.csv");
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


    }
}

void Gestao::readFileAirports() {  // INCOMPLETE
    std::ifstream airports;
    airports.open("../dataset/airports.csv");
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

    }
}

void Gestao::readFileFlights() {  // INCOMPLETE
    std::ifstream flights;
    flights.open("../dataset/flights.csv");
    string line;
    getline(flights, line); // Skip the first line
    while (getline(flights, line)) {
        stringstream inputString(line);
        string FlightSource, FlightTarget, FlightAirline;
        getline(inputString, FlightSource, ',');
        getline(inputString, FlightTarget, ',');
        getline(inputString, FlightAirline, '\r');

    }
}

list<Flight> Gestao::getFlights() const {
    return flights_;
}