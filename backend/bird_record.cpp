//
// Created by Eddy on 5/8/2023.
//

#include "bird_record.h"
#include <sstream>
#include <vector>


bird_record::bird_record(string line) {
    stringstream stream(line);
    string segment;
    vector<std::string> parts;

    while(std::getline(stream, segment, ','))
    {
        parts.push_back(segment);
    }
    xCoord = parts.at(0);
    yCoord = parts.at(1);
    commonName = parts.at(2);
    scientificName = parts.at(3);
    state = parts.at(4);
    county = parts.at(5);
    locality = parts.at(6);
    observationDate = parts.at(7);
}

string bird_record::getX() {
    return xCoord;
}

string bird_record::getY() {
    return yCoord;
}

string bird_record::getRecord() {
    return xCoord + ',' + yCoord + ',' + commonName + ',' + scientificName + ',' + state + ',' + county + ',' + locality + ',' + observationDate;
}

string bird_record::getCommonName() {
    return commonName;
}

string bird_record::getScientificName() {
    return scientificName;
}

string bird_record::getState() {
    return state;
}

string bird_record::getCounty() {
    return county;
}

string bird_record::getLocality() {
    return locality;
}

string bird_record::getObservationDate() {
    return observationDate;
}


