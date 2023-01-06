#ifndef TRABALHOAED2_COUNTRY_H
#define TRABALHOAED2_COUNTRY_H
#include "City.h"
#include "Airline.h"
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Country {
public:
    Country(string name);
    Country(); //default constructor
    string getName() const;  // Returns the name of the country
    unordered_set<string> getCities() const; // Returns the list of cities in the country
    unordered_set<string> getAirlines() const; // Returns the list of airlines in the country
    void addAirline(string al);
    void addCity(string c);
private:
    string name_;
    unordered_set<string> cities_;
    unordered_set<string> airlines_;
};


#endif //TRABALHOAED2_COUNTRY_H
