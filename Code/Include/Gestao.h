#ifndef TRABALHOAED2_GESTAO_H
#define TRABALHOAED2_GESTAO_H

#include <set>
#include <queue>
#include <vector>
#include "Flight.h"
#include "Country.h"

using namespace std;


class Gestao {
public:
    void readFileAirlines(); // Reads the airlines.csv file
    void readFileAirports(); // Reads the airports.csv file
    void readFileFlights(); // Reads the flights.csv file
    list<Flight> getFlights() const; // Returns the list of flights
private:
    list<Flight> flights_; // List of flights
};


#endif //TRABALHOAED2_GESTAO_H
