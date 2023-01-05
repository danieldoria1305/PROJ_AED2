#include "../Include/City.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

City::City(string name): name_(name){}
City::City() {}

string City::getName() const{
    return name_;
}

M_airport City::getAirports() const{
    return airports_;
}

void City::addAirport(const Airport &ap) {
    airports_[ap.getCode()]=ap;
}