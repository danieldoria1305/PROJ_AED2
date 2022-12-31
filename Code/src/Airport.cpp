#include "../Include/Airport.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

Airport::Airport(string code, string name, float longitude, float latitude): code_(code),
name_(name), longitude_(longitude), latitude_(latitude) {}
Airport::Airport() {}

string Airport::getCode() const {
    return code_;
}

string Airport::getName() const {
    return name_;
}

float Airport::getLongitude() const {
    return longitude_;
}

float Airport::getLatitude() const {
    return latitude_;
}
