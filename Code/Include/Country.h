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

struct cityHash
{
    // TODO
    int operator() (const City& c) const {
        string s1=c.getName();
        int v=0;
        for(int i=0;i<s1.size();i++){
            v=v*37+s1[i];
        }
        return v;
    }

    // TODO
    bool operator() (const City& c1, const City& c2) const {
        return c1.getName()==c2.getName();
    }
};

typedef unordered_map<string,City> unMcity;

class Country {
public:
    Country(string name);
    Country(); //default constructor
    string getName() const;  // Returns the name of the country
    unMcity getCities() const; // Returns the list of cities in the country
    list<Airline> getAirlines() const; // Returns the list of airlines in the country
    void addAirline(const Airline& al);
    void addCity(const City& c);
    void addAirport(const Airport& ap,string city);
private:
    string name_;
    unMcity cities_;
    list<Airline> airlines_;
};


#endif //TRABALHOAED2_COUNTRY_H
