
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
        float distance;
    };

    struct Source {
        list<Target> targets;
        bool visited=false;
        int dist;
    };

    unordered_map<string,Source> sources; // Unordered map of Airports being represented
public:
    void addEdge(string source, string target, string airline);
    void bfs(string source);
    int distance(string s, string t);
    double calculateDistance(Airport airport1, Airport airport2); // Calculates the distance between two coordinates using the Haversine formula
};


#endif //TRABALHOAED2_FLIGHTS_H
