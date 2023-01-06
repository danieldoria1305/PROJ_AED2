#ifndef TRABALHOAED2_CITY_H
#define TRABALHOAED2_CITY_H
#include "Airport.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

class City {
public:
    City(string name); // Constructor
    City(); // Default Constructor
    string getName() const; // Returns the name of the city
    unordered_set<string> getAirports() const; // Returns the list of airports of the city
    void addAirport(string ap);
private:
    string name_;
    unordered_set<string> airports_;
};


#endif //TRABALHOAED2_CITY_H
