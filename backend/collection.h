#ifndef collection_H
#define collection_H
#include <string>
#include <vector>
#include "bird_record.h"
#include "parse.h"

using namespace std;

class Collection{
private:
    string fileName;
    vector<bird_record> birds;
    string username;
    string collectionName;
public:
    Collection(string fileName, string name, string username);
    void load();
    void setUsername(string username);
    void show();
    void addRecord(bird_record record);
    void setCollectionName(string name);
};
#endif