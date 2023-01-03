
#ifndef TRABALHOAED2_FLIGHT_H
#define TRABALHOAED2_FLIGHT_H
#include "Airport.h"
#include "Airline.h"
#include <iostream>
#include <unordered_map>

class Flight {
    struct Target {
        string target;
        string airline;
    };

    struct Source {
        list<Target> targets;
        bool visited=false;
    };
public:
    unordered_map<string,Source> sources; // Unordered map of Airports being represented


    Flight();
    void addEdge(string source, string target, string airline);
    unordered_map<string,Source> getSources();
    void bfs(string source);
};


#endif //TRABALHOAED2_FLIGHT_H
