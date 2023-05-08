#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int attributePos(string row, string which, string attributes);

int main() {
    fstream file;
    file.open("eBird_1k_cleaned.csv");
    if(file.fail()){
        cout << "failed\n";
        return -1;
    }
    string attributes;
    getline(file, attributes, '\n');
    cout << attributes << endl;
    cout << endl;

    string lookfor;
    cout << "Possible attributes: \n'XCord'\n'YCord'\n'commonName'\n'scientificName'\n'State'\n'County'\n'Locality'\n'observationDate'\n'userID'\n" << endl;
    cout << "Enter an attribute from above exactly" << endl;
    cin >> lookfor;

    string line;
    getline(file, line, '\n');
    cout << line << endl;
    cout << endl;

    int start = attributePos(line, lookfor, attributes);
    unsigned int end = line.find(',', attributePos(line, "y", attributes))-attributePos(line, "y", attributes);
    cout << line.substr(start, end) << endl;

    file.close();
    return 0;
}

//finds the position in the string of the specified attribute
//row - the record being searched through (a row/entry in the csv)
//which - the attribute being looked for (such as x coordinate, common name, state, etc.)
//attributes - a string that contains all the attributes in the correct order (first row of csv file)
int attributePos(string row, string which, string attributes){
    int end = attributes.find(which);
    int count = 0;
    for(int i=0; i<end; i++){
        if(attributes.at(i) == ','){
            count++;
        }
    }
    int pos = 0;
    while(count > 0){
        if(row.at(pos) == ','){
            count--;
        }
        pos++;
    }
    return pos;
}