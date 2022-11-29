////
//// Created by Annaliese Nartey  & Wendy Pasiah on 11/26/2022.
////
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

#ifndef UNTITLED2_AIRLINES_H
#define UNTITLED2_AIRLINES_H


#endif //UNTITLED2_AIRLINES_H
/**
 * @authors Annaliese Nartey & Wendy Pasiah
 */

class Airlines {
private:
    /* Instance variables/Fields*/
    int airline_id;
    string airline_name;
    string alias;
    string airlineIata;
    string airlineIcao;
    string callsign;
    string country;
    string active;
public:          // Access specifier
    /**
     * Constructor declaration
     * @param id  the unique OpenFlights identifier for the airline.
     * @param name the name of airline.
     * @param aka the also known as of the airline.
     * @param iata  the 2-letter IATA code
     * @param icao  the 3-letter ICAO code
     * @param calsign  the Airline callsign.
     * @param country   the airline origin country
     * @param active   determines if the airline is in use or not
     */

    Airlines(int id, string name, string aka, string iata, string icao, string calsign, string country, string active);


    /**
     * @returns none
     * This method reads the airlines file, splits the lines in the file, and stores the values in a map
     * The keys of the map are strings and the values are vectors of Airline objects
     */
    static void reader();
    static map<string, vector<Airlines>> Hmap;
};
