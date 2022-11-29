////
//// Created by Annaliese Nartey on 11/26/2022.
////

#include "Routes.h"

Routes::Routes(string airline, string airline_id, string source_airport, string sourceair_id, string destin,
               string destin_id, string stops) {
    this->airline = airline;
    this->airline_id = airline_id;
    this->source_airport = source_airport;
    this->sourceAir_id = sourceair_id;
    this->destinAir = destin;
    this->destinAir_id =destin_id;
    this->stops = stops;

}

void Routes::reader() {
    ifstream file;
    file.open("routes.csv");
    string line = "";
    int count = 0;
    string key, Akey;
    if (file.is_open()) {

        while (getline(file, line)) {
            if (count == 0) {
                count++;
                continue;
            }
            string airline, airline_id, source_airport, sourceair_id, destin, destin_id, codeshare, stops, equipment;

            stringstream inputString(line);

            getline(inputString, airline, ',');
            getline(inputString, airline_id, ',');
            getline(inputString, source_airport, ',');
            getline(inputString, sourceair_id, ',');
            getline(inputString, destin, ',');
            getline(inputString, destin_id, ',');
            getline(inputString, codeshare, ',');
            getline(inputString, stops, ',');
            getline(inputString, equipment, ',');


            key = source_airport;

            Akey = source_airport + ", "+ destin;


            Routes route = *new Routes(airline, airline_id, source_airport,  sourceair_id,  destin,destin_id,  stops);
            Routes::Amap.insert({Akey, route});

            /**this section checks if there is already a key in the map with the same name.
            * if it does, it adds the new object to the vector belonging to the particular key already in the map
            */

            if (Routes::Hmap.find(key) == Routes::Hmap.end()){
                vector<Routes> lists;
                lists.push_back(route);
                Routes::Hmap.insert({ key, lists });}

            else{
                Hmap[key].push_back(route);
            }
        }
    }
    else {
        cout << "Sorry cannot open";
    }
    file.close();

}
