//
// Created by pedropassos on 02-01-2023.
//

#include "../Include/Gestao.h"

int main(){
    Gestao g;
    g.readFileAirlines();
    g.readFileAirports();
    g.printAllAirports();
}
