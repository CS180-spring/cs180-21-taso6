#include "collection.h"

Collection::Collection(string fileName, string name, string username){
    this->fileName = fileName;
    this->collectionName = name;
    this->username = username;
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
}

void Collection::setCollectionName(string name) {
    collectionName = name;
}
