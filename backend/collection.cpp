#include "collection.h"
#include <iostream>

Collection::Collection(string fName, string name, string uName){
    std::cout << "STUFF: " << fileName << ", " << name << ", " << username << std::endl;
    fileName = fName;
    collectionName = name;
    username = uName;
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