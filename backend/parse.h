#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Finds the position in the string of the specified attribute
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

//Finds the specified attribute in a csv file on a certain line
//fileName - the name of the file to look in
//lookfor - the name of the attribute in the csv file
//lineNumber - the line the function should look at
//The first line with the name of all the attributes is considered line 0,
  //so the parameter '1' will search through the first line.
string parseCSV(string fileName, string lookfor, int lineNumber) {
    fstream file;
    file.open(fileName);
    if(file.fail()){
        cout << "failed\n";
        exit(-1) ;
    }
    string attributes;
    getline(file, attributes, '\n');
    // cout << attributes << endl;
    // cout << endl;

    // string lookfor;
    // cout << "Enter an attribute from above exactly" << endl;
    // cin >> lookfor;

    string line;
    for(int i=0; i<lineNumber; i++){
        getline(file, line, '\n');
        // cout << line << endl;
        // cout << endl;
    }

    int start = attributePos(line, lookfor, attributes);
    unsigned int end = line.find(',', attributePos(line, "y", attributes))-attributePos(line, "y", attributes);
    file.close();
    return line.substr(start, end+1);
}

vector<string> parseAllCSV(string fileName, string lookfor) {
    fstream file;
    file.open(fileName);
    if (file.fail()) {
        cout << "failed\n";
        exit(-1);
    }
    vector<string> list;
    string attributes;
    getline(file, attributes, '\n');
    // cout << attributes << endl;
    // cout << endl;

    // string lookfor;
    // cout << "Enter an attribute from above exactly" << endl;
    // cin >> lookfor;

    string line;
    while (getline(file, line, '\n')){
        // cout << line << endl;
        // cout << endl;

        int start = attributePos(line, lookfor, attributes);
        unsigned int end = line.find(',', attributePos(line, "y", attributes)) - attributePos(line, "y", attributes);
//        cout << line.substr(start, end+1);
        list.push_back(line.substr(start, end));
    }
    file.close();
    return list;
}