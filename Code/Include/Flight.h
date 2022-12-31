
#ifndef TRABALHOAED2_FLIGHT_H
#define TRABALHOAED2_FLIGHT_H
#include "Airport.h"
#include "Airline.h"
#include <iostream>

class Flight {
public:
    Flight(Airport source, Airport target); // Constructor
    Flight(); // Default constructor
    Airport getSource() const; // Get Flight source airport
    Airport getTarget() const; // Get Flight target airport
private:
    Airport source_; // Flight source airport
    Airport target_; // Flight target airport
    Airline airline_; // Flight airline
};


#endif //TRABALHOAED2_FLIGHT_H
