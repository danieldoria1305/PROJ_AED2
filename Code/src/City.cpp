#include "../Include/City.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

City::City(string name, list<Airport> airports): name_(name), airports_(airports) {}
City::City() {}

string City::getName() const{
    return name_;
}

list<Airport> City::getAirports() const{
    return airports_;
}

