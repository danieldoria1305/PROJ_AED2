
#ifndef TRABALHOAED2_FLIGHTS_H
#define TRABALHOAED2_FLIGHTS_H
#include "Airport.h"
#include "Airline.h"
#include <iostream>
#include <unordered_map>

class Flights {
    struct Target {
        string target;
        string airline;
    };

    struct Source {
        list<Target> targets;
        bool visited=false;
    };

    unordered_map<string,Source> sources; // Unordered map of Airports being represented

public:
    Flights();
    void addEdge(string source, string target, string airline);
    void bfs(string source);
};


#endif //TRABALHOAED2_FLIGHTS_H
