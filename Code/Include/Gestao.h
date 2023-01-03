#ifndef TRABALHOAED2_GESTAO_H
#define TRABALHOAED2_GESTAO_H

#include <set>
#include <queue>
#include <vector>
#include "Flight.h"
#include "Country.h"
#include "Airport.h"
#include <unordered_map>

using namespace std;

typedef unordered_map<string,Country> unMcountry;

class Gestao {
public:
    void readFileAirlines(); // Reads the airlines.csv file
    void readFileAirports(); // Reads the airports.csv file
    void readFileFlights(); // Reads the flights.csv file
    double calculateDistance(Airport airport1, Airport airport2); // Calculates the distance between two coordinates using the Haversine formula
private:
    unMcountry countries_; // Unordered_map of countries
    Flight flights; // Graph of flights
};


#endif //TRABALHOAED2_GESTAO_H
