#include "../Include/Flight.h"
#include <iostream>
#include <queue>

Flight::Flight() {}

void Flight::addEdge(string source, string target, string airline) {
    if(sources.find(source)==sources.end()){
        sources[source]={};
    }
    auto it=sources.find(source);
    Target t=Target();
    it->second.targets.push_back({target,airline});
}

void Flight::bfs(string source) {
    for (auto& s:sources){
        s.second.visited=false;
    }
    queue<string> q;
    q.push(source);
    auto it=sources.find(source);
    it->second.visited = true;
    while (!q.empty()) {
        string u = q.front(); q.pop();
        it=sources.find(u);
        for (auto e : it->second.targets) {
            string w = e.target;
            auto it2=sources.find(u);
            if (!it2->second.visited) {
                q.push(w);
                it2=sources.find(w);
                it2->second.visited = true;
            }
        }
    }
}