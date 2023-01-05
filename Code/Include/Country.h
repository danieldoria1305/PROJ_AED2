#ifndef TRABALHOAED2_COUNTRY_H
#define TRABALHOAED2_COUNTRY_H
#include "City.h"
#include "Airline.h"
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

typedef unordered_map<string,City> M_city;

class Country {
public:
    Country(string name);
    Country(); //default constructor
    string getName() const;  // Returns the name of the country
    M_city getCities() const; // Returns the list of cities in the country
    list<Airline> getAirlines() const; // Returns the list of airlines in the country
    void addAirline(const Airline& al);
    void addCity(const City& c);
    void addAirport(const Airport& ap,string city);
private:
    string name_;
    M_city cities_;
    list<Airline> airlines_;
};


#endif //TRABALHOAED2_COUNTRY_H
