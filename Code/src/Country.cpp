#include "../Include/Country.h"
#include <string>
#include <vector>
#include <list>

Country::Country(string name, list<City> cities, list<Airline> airlines): name_(name),
cities_(cities), airlines_(airlines){}
Country::Country(){} //default constructor

string Country::getName() const {  // Returns the name of the country
    return name_;
}

list<City> Country::getCities() const { // Returns the list of cities in the country
    return cities_;
}

list<Airline> Country::getAirlines() const { // Returns the list of airlines in the country
    return airlines_;
}
