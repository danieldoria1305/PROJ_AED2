#ifndef TRABALHOAED2_CITY_H
#define TRABALHOAED2_CITY_H
#include "Airport.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

typedef unordered_map<string,Airport> unMairport;

class City {
public:
    City(string name); // Constructor
    City(); // Default Constructor
    string getName() const; // Returns the name of the city
    unMairport getAirports() const; // Returns the list of airports of the city
    void addAirport(const Airport& ap);
private:
    string name_;
    unMairport airports_;
};


#endif //TRABALHOAED2_CITY_H
