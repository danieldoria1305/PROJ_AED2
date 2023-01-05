#include "../Include/Country.h"
#include <string>
#include <vector>
#include <list>

Country::Country(string name): name_(name){}
Country::Country(){} //default constructor

string Country::getName() const {  // Returns the name of the country
    return name_;
}

M_city Country::getCities() const { // Returns the list of cities in the country
    return cities_;
}

list<Airline> Country::getAirlines() const { // Returns the list of airlines in the country
    return airlines_;
}

void Country::addAirline(const Airline &al) {
    airlines_.push_back(al);
}

void Country::addCity(const City &c) {
    cities_[c.getName()]=c;
}

void Country::addAirport(const Airport &ap, string city) {
    auto it = cities_.find(city);
    if(it==cities_.end()){
        City c(city);
        addCity(c);
    }
    it = cities_.find(city);
    it->second.addAirport(ap);
}
