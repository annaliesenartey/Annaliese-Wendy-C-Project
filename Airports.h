///
/// Created by Annaliese Nartey & Wendy Pasiah on 11/26/2022.

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

#ifndef UNTITLED2_AIRPORTS_H
#define UNTITLED2_AIRPORTS_H


class Airports {

public:
    // Instance variables/Fields
    string airport_id;
    string name;
    string city;
    string country;
    string iata_code;
    string icao_code;
//    string cod;
//    string stops;
//    string equipment;

/**
 * Constructor declaration
 * Build and initialise objects of this class
 * @param airport_id  the unique OpenFlights identifier for the airport.
 * @param name  the name of airport.
 * @param city  the main city served by airport.
 * @param country  the country where airport is located.
 * @param iata_code  the 3-letter IATA code
 * @param icao_code  the 4-letter ICAO code
 */
    Airports(string airport_id, string name, string city, \
           string country, string iata_code, string icao_code);


    /**
    * @returns none
    * This method reads the airports file, splits the lines in the file, and stores the values in a map
    * The keys of the map are strings and the values are vectors of Airport objects
    */
    static void reader();
    static map<string, vector<Airports>> Hmap;

};


#endif //UNTITLED2_AIRPORTS_H
