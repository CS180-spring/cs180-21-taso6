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
    BirdRecord baseDat;

    // read in the column names
    getline(file,in);


    // for(int i = 0;i < 9; i++){
        getline(file, serialNum, ',');
        cout << serialNum << endl;

        getline(file, XCord, ',');
        cout << XCord << endl;
        
        getline(file, YCord, ',');
        cout << YCord << endl;

        getline(file, commonName, ',');
        cout << commonName << endl;

        getline(file, scientificName, ',');
        cout << scientificName << endl;

        getline(file, State, ',');
        cout << State << endl;
        
        getline(file, County, ',');
        cout << County << endl;

        getline(file, Locality, ',');
        cout << Locality << endl;

        getline(file, obsDate, ',');
        cout << obsDate << endl;

        getline(file, userID);
        cout << userID << endl;
        
        // getline(file, in, ',');
        // cout << in << endl;
        // cout << endl;
    // }

    // vector<vector<string>> content;
	// vector<string> row;

    // while(getline(file, line))
	// 	{
	// 		row.clear();
 
	// 		stringstream str(line);
 
	// 		while(getline(str, word, ','))
	// 			row.push_back(word);
	// 		content.push_back(row);
	// 	}

    // 9 attributes


    return 0;
}