#ifndef TRABALHOAED2_COUNTRY_H
#define TRABALHOAED2_COUNTRY_H
#include "City.h"
#include "Airline.h"
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Country {
public:
    Country(string name, list<City> cities, list<Airline> airlines);
    Country(); //default constructor
    string getName() const;  // Returns the name of the country
    list<City> getCities() const; // Returns the list of cities in the country
    list<Airline> getAirlines() const; // Returns the list of airlines in the country
private:
    string name_;
    list<City> cities_;
    list<Airline> airlines_;
};


#endif //TRABALHOAED2_COUNTRY_H
