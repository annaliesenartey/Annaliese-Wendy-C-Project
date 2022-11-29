////
//// Created by Annaliese Nartey & Wendy Pasiah on 11/26/2022.
////
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

#ifndef UNTITLED2_ROUTES_H
#define UNTITLED2_ROUTES_H


class Routes {
public:
    // Instance variables /Fields
    string airline;
    string airline_id;
    string source_airport;
    string sourceAir_id;
    string destinAir;
    string destinAir_id;
    string stops;


    /**
     * Constructor declaration
     * Build and initialise objects of this class
     * @param airline the 2-letter (IATA) or 3-letter (ICAO) code of the airline.
     * @param airline_id the unique OpenFlights identifier for airline
     * @param source_airport the Unique OpenFlights identifier for source airport
     * @param sourceair_id the Unique OpenFlights identifier for source airport
     * @param destin the 3-letter (IATA) or 4-letter (ICAO) code of the destination airport
     * @param destin_id  the unique OpenFlights identifier for airline
     * @param stops the number of stops on this flight ("0" for direct)
	 */

    Routes(string airline, string airline_id, string source_airport, \
           string sourceair_id, string destin, string destin_id,  string stops);


    /**
     * @returns none
     * This method reads the routes file, splits the lines in the file, and stores the values in a map
    * The keys of the map are strings and the values are vectors of Route objects
     */
    static void reader();
    static map<string, vector<Routes>> Hmap;
    static map<string, Routes> Amap;


};


#endif //UNTITLED2_ROUTES_H
