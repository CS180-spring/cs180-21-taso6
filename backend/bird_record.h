//
// Created by Eddy on 5/8/2023.
//

#ifndef CS180_21_TASO6_BIRD_RECORD_H
#define CS180_21_TASO6_BIRD_RECORD_H
#include <string>
//#include "parse.h"

using namespace std;

class bird_record {
private:
    string xCoord; //x
    string yCoord; //y
    string commonName; //COMMON NAME
    string scientificName; //SCIENTIFIC NAME
    string state; //STATE
    string county; //COUNTY
    string locality; //LOCALITY
    string observationDate; //TIME OBSERVATIONS STARTED
public:
    bird_record(string line);
    string getX();
    string getY();
    string getRecord();
    string getCommonName();
    string getScientificName();
    string getState();
    string getCounty();
    string getLocality();
    string getObservationDate();
};


#endif //CS180_21_TASO6_BIRD_RECORD_H
