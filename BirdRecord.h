#include <string>
#include <iostream>

using namespace std;

#ifndef _BIRDRECORD_H_
#define _BIRDRECORD_H_



class BirdRecord
{
private:
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
public:
    BirdRecord();
    BirdRecord(string serialNum, string XCord, string YCord, string commonName, string scientificName, string State, string County, string Locality, string obsDate, string userID) { serialNum = serialNum, XCord = XCord, YCord = YCord, commonName = commonName, scientificName = scientificName, State = State, County = County, Locality = Locality, obsDate = obsDate, userID = userID; };
    ~BirdRecord();

    string GetSerialNum(){return serialNum;};
    void SetSerialNum(string serialNum){serialNum = serialNum;};

    string GetXCord(){return XCord;};
    void SetXCord(string xCord){XCord = xCord;};

    string GetYCord(){return YCord;};
    void SetYCord(string yCord){YCord = yCord;};

    string GetCommonName(){return commonName;};
    void SetCommonName(string CommonName){commonName = CommonName;};

    string GetScientificName(){return scientificName;};
    void SetScientificName(string ScientificName){scientificName = ScientificName;};

    string GetState(){return State;};
    void SetState(string state){State = state;};

    string GetCounty(){return County;};
    void SetCounty(string county){County = county;};

    string GetLocality(){return Locality;};
    void SetLocality(string locality){Locality = locality;};

    string GetObsDate(){return obsDate;};
    void SetObsDate(string ObsDate){obsDate = ObsDate;};

    string GetUserID(){return userID;};
    void SetUserID(string UserID){userID = UserID;};

};

BirdRecord::BirdRecord(/* args */)
{
}

BirdRecord::~BirdRecord()
{
}





#endif