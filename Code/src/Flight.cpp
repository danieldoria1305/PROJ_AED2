#include "../Include/Flight.h"
#include <iostream>

Flight::Flight(Airport source, Airport target): source_(source), target_(target) {}
Flight::Flight() {}

Airport Flight::getSource() const {
    return source_;
}

Airport Flight::getTarget() const {
    return target_;
}
