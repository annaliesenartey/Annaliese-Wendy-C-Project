///
/// Created by Annaliese Nartey on 11/26/2022.
///
#include "Airports.h"

Airports::Airports(std::string airport_id, std::string name, std::string city, std::string country,
                   std::string iata_code, std::string icao_code) {
    this->airport_id= airport_id;
    this->name= name;
    this->city= city;
    this->country= country;
    this->iata_code= iata_code;
    this->icao_code = icao_code;
}

void Airports::reader() {
    ifstream file;
    file.open("airports.csv");
    string line = "";
    int count = 0;
    string key;
    if (file.is_open()) {

        while (getline(file, line)) {
            if (count == 0) {
                count++;
                continue;
            }
            string airport_id,  name, city, country, iata_code, icao_code;

            stringstream inputString(line);

            getline(inputString, airport_id, ',');
            getline(inputString, name, ',');
            getline(inputString, city, ',');
            getline(inputString, country, ',');
            getline(inputString, iata_code, ',');
            getline(inputString, icao_code, ',');


            key = city + ", "+ country;


            Airports airport = *new Airports(airport_id,  name, city, country, iata_code, icao_code);
            /**this section checks if there is already a key in the map with the same name.
             * if it does, it adds the new object to the vector belonging to the particular key already in the map
             */
            if (Airports::Hmap.find(key) == Airports::Hmap.end()){
                vector<Airports> lists;
                lists.push_back(airport);
                Airports::Hmap.insert({ key, lists });}

            else{
                Hmap[key].push_back(airport);
            }
        }
    }
    else {
        cout << "Sorry cannot open";
    }
    file.close();
}