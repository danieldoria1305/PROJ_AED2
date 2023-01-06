#include "../Include/Airline.h"
#include <string>
#include <list>

Airline::Airline(string code, string name, string callsign, string country): code_(code),
name_(name), callsign_(callsign), country_(country){}
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

string Airline::getCountry() const {
    return country_;
}
