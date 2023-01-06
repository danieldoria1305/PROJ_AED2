#include "../Include/Flights.h"
#include <iostream>
#include <queue>

void Flights::addEdge(string source, string target, string airline) {
    if(sources.find(source)==sources.end()){
        sources[source]={};
    }
    if(sources.find(target)==sources.end()){
        sources[target]={};
    }
    sources[source].targets.push_back({target,airline});
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

int Flights::distance(string s, string t){
    bfs(s);
    return sources[t].dist;
}
