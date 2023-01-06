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

class Gestao {
public:
    void readFileAirlines(); // Reads the airlines.csv file
    void readFileAirports(); // Reads the airports.csv file
    void readFileFlights(); // Reads the flights.csv file
    int getDistance(string a,string b);

private:
    M_country countries_; // Unordered_map of countries
    Flights flights_; // Graph of flights
    M_airport airports_;
};


#endif //TRABALHOAED2_GESTAO_H
