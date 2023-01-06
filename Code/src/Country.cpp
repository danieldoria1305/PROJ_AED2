#include "../Include/Country.h"
#include <string>
#include <vector>
#include <list>

Country::Country(string name): name_(name){}
Country::Country(){} //default constructor

string Country::getName() const {  // Returns the name of the country
    return name_;
}

unordered_set<string> Country::getCities() const { // Returns the list of cities in the country
    return cities_;
}

unordered_set<string> Country::getAirlines() const { // Returns the list of airlines in the country
    return airlines_;
}

void Country::addAirline(string al) {
    airlines_.insert(al);
}

void Country::addCity(string c) {
    cities_.insert(c);
}
