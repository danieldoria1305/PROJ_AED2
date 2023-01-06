#include "../Include/Flights.h"
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

void Flights::addEdge(Airport source, Airport target, string airline) {
    if(sources.find(source.getCode())==sources.end()){
        sources[source.getCode()]={};
    }
    if(sources.find(target.getCode())==sources.end()){
        sources[target.getCode()]={};
    }
    sources[source.getCode()].targets.push_back({target.getCode(),airline, calculateDistance(source,target)});
}

void Flights::bfs(string source) {
    for (auto& s:sources){
        s.second.visited=false;
        s.second.dist=-1;
    }
    queue<string> q;
    q.push(source);
    sources[source].visited = true;
    sources[source].dist=0;
    while (!q.empty()) {
        string u = q.front(); q.pop();
        for (auto e : sources[u].targets) {
            string w = e.target;
            if (!sources[w].visited) {
                q.push(w);
                sources[w].dist=sources[u].dist+1;
                sources[w].visited = true;
            }
        }
    }
}

vector<string> Flights::dijkstra(string src, string dest) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    unordered_map<string, string> prev;

    for (auto& pair: sources) {
        pair.second.dist=INT_MAX;
    }

    sources[src].dist = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        string u = pq.top().second;pq.pop();
        if (u == dest) {
            break;
        }
        for (auto e : sources[u].targets) {
            string w=e.target;
            int alt = sources[u].dist + 1;
            if (alt < sources[w].dist) {
                sources[w].dist = alt;
                prev[w] = u;
                pq.emplace(alt, w);
            }
        }
    }
    vector<string> result;
    string u=dest;
    while(u!=src) {
        result.push_back(u);
        u=prev[u];
    }
    result.push_back(src);
    return result;
}

double Flights::calculateDistance(Airport airport1, Airport airport2) {
    float long1 = airport1.getLongitude();
    float lat1 = airport1.getLatitude();
    lat1 = (lat1) * M_PI / 180.0;

    float long2 = airport2.getLongitude();
    float lat2 = airport2.getLatitude();
    lat2 = (lat2) * M_PI / 180.0;

    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLong = (long2 - long1) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) * pow(sin(dLong / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

unordered_map<string, Flights::Source> Flights::getSources() {
    return sources;
}
