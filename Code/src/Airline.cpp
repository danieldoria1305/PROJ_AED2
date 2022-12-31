#include "../Include/Airline.h"
#include <string>
#include <list>

Airline::Airline(string code, string name, string callsign, list<Flight> flights): code_(code),
name_(name), callsign_(callsign), flights_(flights) {}
Airline::Airline() {}

string Airline::getCode() const {
    return code_;
}

string Airline::getName() const {
    return name_;
}

string Airline::getCallSign() const {
    return callsign_;
}

list<Flight> Airline::getFlights() const {
    return flights_;
}
