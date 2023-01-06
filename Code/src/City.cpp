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

unordered_set<string> City::getAirports() const{
    return airports_;
}

void City::addAirport(string ap) {
    airports_.insert(ap);
}