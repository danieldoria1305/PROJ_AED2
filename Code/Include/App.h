#ifndef TRABALHOAED2_APP_H
#define TRABALHOAED2_APP_H
#include "Gestao.h"


class App {
public:
    void start(); // Starts the application
    bool printUserMenu(); // Prints the User Menu/Interface
    void printNumberOfFlights(); // Prints the number of flights starting from a certain airport
    void printNumberOfAirlines(); // Prints the number of different airlines
    void printNumberOfArrivals(); // Prints the number of arrivals
    void printNumberOfCountries(); // Prints the number of countries
    void printHowFar();
    void printBestWayToFly();
    void printAirlinesMenu();
    void printBestWayToFlyCities();
private:
    Gestao gestao;
    set<string> airlines_;
    string type_;
};


#endif //TRABALHOAED2_APP_H
