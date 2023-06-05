#include "collection.h"
#include <iostream>
#include <fstream>
#include <cstring>

Collection::Collection(string fName, string name, string uName){
    std::cout << "STUFF: " << fName << ", " << name << ", " << uName << std::endl;
    fileName = fName;
    collectionName = name;
    username = uName;
    string directory = "assets/";
    string extend = ".csv";
    string result = directory + uName + "-" + name + extend;

    fstream file;
    file.open(result, ios_base::out);

    if(!file){
       std::cout << "Error in file Creation! at File" << endl;
    }
    else{
        std::cout << "File Creation successful." << endl;
    }
//    const int length=result.length();
//    char* input = new char[length+1];
//    std::strcpy(input, result.c_str());
//
    file.close();
    load();
}

void Collection::load() {
    vector<string> temp = parseCSVforDB(fileName);
    for(int i=0; i<temp.size(); i++){
        bird_record record(temp.at(i));
        birds.push_back(record);
    }
}

void Collection::setUsername(string username) {
    this->username = username;
}

void Collection::show() {
    for(int i=0; i<birds.size(); i++){
        cout << birds.at(i).getRecord() << endl;
    }
}

void Collection::addRecord(bird_record record) {
    birds.push_back(record);
    ofstream file(fileName, std::ios_base::app);
    file << record.getRecord();
    file.close();
}

void Collection::setCollectionName(string name) {
    collectionName = name;
}

string Collection::getCollectionName(){
    return collectionName;
}
string Collection::getUsername(){
    return username;
}
bird_record Collection::getBird(int index){
    return birds.at(index);
}

int Collection::size() {
    return birds.size();
}

Collection::Collection(Collection const &cpy){
    fileName = cpy.fileName;
    birds = cpy.birds;
    username = cpy.username;
    collectionName = cpy.collectionName;
}