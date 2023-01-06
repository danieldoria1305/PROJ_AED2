#ifndef TRABALHOAED2_AIRLINE_H
#define TRABALHOAED2_AIRLINE_H
#include <string>
#include <list>

using namespace std;

class Airline {
public:
    Airline(string code, string name, string callsign, string country); // Constructor
    Airline();  // Default Constructor
    string getCode() const; // Returns the code of the airline
    string getName() const; // Returns the name of the airline
    string getCallSign() const; // Returns the callsign of the airline
    string getCountry() const; // Returns the country of the airline

private:
    string code_; // Code of the airline
    string name_; // Name of the airline
    string callsign_; // Callsign of the airline
    string country_; // Country of the airline
};


#endif //TRABALHOAED2_AIRLINE_H
