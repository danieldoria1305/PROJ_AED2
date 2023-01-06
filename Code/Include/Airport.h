#ifndef TRABALHOAED2_AIRPORT_H
#define TRABALHOAED2_AIRPORT_H
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Airport {
public:
    Airport(string code, string name, string city, string country, float longitude, float latitude); // Constructor
    Airport(); // Default Constructor
    string getCode() const; // Get Airport Code
    string getName() const; // Get Airport Name
    string getCity() const; // Get Airport City
    string getCountry() const; // Get Airport Country
    float getLongitude() const; // Get Airport Longitude
    float getLatitude() const; // Get Airport Latitude
private:
    string code_; // Airport Code
    string name_; // Airport Name
    string city_; // Airport City
    string country_; // Airport Country
    float longitude_; // Airport Longitude
    float latitude_; // Airport Latitude
};


#endif //TRABALHOAED2_AIRPORT_H
