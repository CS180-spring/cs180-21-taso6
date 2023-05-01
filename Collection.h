#ifndef COLLECTION_H
#define COLLECTION_H

#include "BirdRecord.h"

class Collection
{
private:
    vector<BirdRecord> collectionName;
    string username;
public:
    Collection();
    Collection(string Username) {username = Username;};
    ~Collection();
    void searchBird(string commonName);
    void editData(int index, string choice);
    void sort(string category);
    void createInstance(BirdRecord record);
};


#endif