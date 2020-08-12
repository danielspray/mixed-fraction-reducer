// Driver.cpp creates a vector of reduced fractions after reading in the list of random fractions from a file
// assumes the file has one of two formats for fractions. 1. #^*/#^* 2. #^*_#^*/#^* : EX: 1/2, 10/320, 1_4/22
// assumes all fractions are positive

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Fraction.h"

using namespace std;

// method forward declaration
bool readFromFile(string fileName, vector<Fraction*> *fractions);
void printFractions(vector<Fraction*> *fractions);

int main() {
  // the list of fractions
  vector<Fraction*> *fractions = new vector<Fraction*>;

  // read fractions in from file and add them to the fractions vector
  // make sure file name is valid, if not print error message
  if (readFromFile("fractionList.txt", fractions)) {
    // print the vector of fractions
    printFractions(fractions);
  }
  else {
    cout << "ERROR: File not found" << endl;
    return -1;
  }
  // delete the heap data
  for (int i = 0; i < fractions->size(); i++) {
    cout << "Deleting: " << *fractions->at(i) << endl;
    delete fractions->at(i);
  }
  cout << "Deleting fractions vector" << endl;
  delete fractions;

  return 0;
}

// reads in the list of fractions from the file name and adds them to the vector of Fractions
bool readFromFile(string fileName, vector<Fraction*> *fractions) {
  ifstream theFile(fileName);
  string line;
  if (theFile.is_open()) {
    while (getline(theFile, line)) {

      // check if line is a mixed fraction ------ this if statment is true if the _ is contained within the 'line'
      if (line.find("_") != string::npos) {
        // is mixed fraction
        // first create the strings of each value, because it is uncertain how many digits each value is
        string wholeStr = "";
        string numeratorStr = "";
        string denominatorStr = "";
        int index = 0;
        while (line[index] != '_') {
          wholeStr += line[index];
          index++;
        }
        // add one more to index to get off the underscore
        index++;
        // now add the numbers to the numerator value until division sign (/)
        while (line[index] != '/') {
          numeratorStr += line[index];
          index++;
        }
        // add one more to index to get off the division sign
        index++;
        while (line[index]) {
          denominatorStr += line[index];
          index++;
        }
        if (stoi(denominatorStr) == 0) {
          cout << "ERROR: DIVIDE BY 0, discarding fraction" << endl;
        }
        else {
          // convert the string value to integers and create the Fraction
          Fraction* fractionToAdd = new Fraction(stoi(wholeStr), stoi(numeratorStr), stoi(denominatorStr));
          // add the Fraction to the list of Fractions
          fractions->push_back(fractionToAdd);
        }
      }
      else {
        // regular fraction
        string numeratorStr = "";
        string denominatorStr = "";

        int index = 0;

        // add the numbers to the numerator value until division sign (/)
        while (line[index] != '/') {
          numeratorStr += line[index];
          index++;
        }
        // add one more to index to get off the division sign
        index++;
        while (line[index]) {
          denominatorStr += line[index];
          index++;
        }
        if (stoi(denominatorStr) == 0) {
          cout << "ERROR: DIVIDE BY 0, discarding fraction" << endl;
        }
        else {
          // convert the string value to integers and create the Fraction
          Fraction* fractionToAdd = new Fraction(stoi(numeratorStr), stoi(denominatorStr));
          // add the Fraction to the list of Fractions
          fractions->push_back(fractionToAdd);
        }
      }
    }
  }
  else {
    return false;
  }
  theFile.close();
  // file was found and added each valid fraction line from the file
  return true;
}

void printFractions(vector<Fraction*> *fractions) {
  for (int i = 0; i < fractions->size(); i++) {
    cout << *fractions->at(i) << endl;
  }
}
