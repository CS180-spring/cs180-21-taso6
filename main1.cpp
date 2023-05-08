#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Collection.h"
#include "BirdRecord.h"

using namespace std;

int main() {
    fstream file;
    file.open("eBird_1k_cleaned.csv");
    if(file.fail()){
        cout << "failed\n";
        return -1;
    }

    string serialNum;
    string XCord;
    string YCord;
    string commonName;
    string scientificName;
    string State;
    string County;
    string Locality;
    string obsDate;
    string userID;

    string in;
    
    string username = "baseline";
    vector<BirdRecord> baselineCollection;

    // read in the column names
    getline(file,in);

    BirdRecord baseDat;

    for(int i = 0;i < 1000; i++){
        getline(file, serialNum, ',');
        baseDat.SetSerialNum(serialNum);

        getline(file, XCord, ',');
        baseDat.SetXCord(XCord);
        
        getline(file, YCord, ',');
        baseDat.SetYCord(YCord);

        getline(file, commonName, ',');
        baseDat.SetCommonName(commonName);

        getline(file, scientificName, ',');
        baseDat.SetScientificName(scientificName);

        getline(file, State, ',');
        baseDat.SetState(State);
        
        getline(file, County, ',');
        baseDat.SetCounty(County);

        getline(file, Locality, ',');
        baseDat.SetLocality(Locality);

        getline(file, obsDate, ',');
        baseDat.SetObsDate(obsDate);

        getline(file, userID);
        baseDat.SetUserID(userID);
        
        baselineCollection.push_back(baseDat);
    }

    // Collection col1;
    // col1.setCol(baselineCollection);

    file.close();


    return 0;
}