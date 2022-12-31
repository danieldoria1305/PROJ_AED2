#ifndef TRABALHOAED2_CITY_H
#define TRABALHOAED2_CITY_H
#include "Airport.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class City {
public:
    City(string name, list<Airport> airports); // Constructor
    City(); // Default Constructor
    string getName() const; // Returns the name of the city
    list<Airport> getAirports() const; // Returns the list of airports of the city
private:
    string name_;
    list<Airport> airports_;
};


#endif //TRABALHOAED2_CITY_H
