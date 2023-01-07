#ifndef TRABALHOAED2_GESTAO_H
#define TRABALHOAED2_GESTAO_H

#include <set>
#include <queue>
#include <vector>
#include "Flights.h"
#include "Country.h"
#include "Airport.h"
#include <unordered_map>

using namespace std;

typedef unordered_map<string,Country> M_country;
typedef unordered_map<string,Airport> M_airport;
typedef unordered_map<string,City> M_city;
typedef unordered_map<string,Airline> M_airline;

class Gestao {
public:
    void readFileAirlines(); // Reads the airlines.csv file
    void readFileAirports(); // Reads the airports.csv file
    void readFileFlights(); // Reads the flights.csv file
    vector<string> getDistance(string a, string b,set<string> airlines);
    M_airport getAirports() const;
    Flights getFlights() const;
    M_airline getAirlines() const;
    M_country getCountries() const;
    M_city getCities() const;
    vector<pair<string,double>> getHowFar(int i,string src);
private:
    M_country countries_; // Unordered_map of countries
    M_city cities_;
    M_airport airports_;
    M_airline airlines_;
    Flights flights_; // Graph of flights
};


#endif //TRABALHOAED2_GESTAO_H
