#ifndef parse_h
#define parse_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Finds the position in the string of the specified attribute
//row - the record being searched through (a row/entry in the csv)
//which - the attribute being looked for (such as x coordinate, common name, state, etc.)
//attributes - a string that contains all the attributes in the correct order (first row of csv file)
int attributePos(string row, string which, string attributes);

//Finds the specified attribute in a csv file on a certain line
//fileName - the name of the file to look in
//lookfor - the name of the attribute in the csv file
//lineNumber - the line the function should look at
//The first line with the name of all the attributes is considered line 0,
  //so the parameter '1' will search through the first line.
string parseCSV(string fileName, string lookfor, int lineNumber);

vector<string> parseAllCSV(string fileName, string lookfor);

vector<string> parseCSVforDB(string fileName);

vector<string> parseCSVforUsers(string fileName);

#endif