#include <string>
#include <iostream>
#include <fstream>
#include "FileFunction.h"
#include "Blacklist.txt"
using namespace std;

void WriteURLtoFile(string& URL) {
    string blacklistFile = "Blacklist.txt";
    ofstream outputFile(blacklistFile, ios::app);
    if (outputFile.is_open()) {
        outputFile << URL << endl;
        outputFile.close();
    } else {
        cout << "Unable to open file for writing: " << blacklistFile << endl;
    }
}

string ReadLineFromFile(int index) {
    string blacklistFile = "Blacklist.txt";
    ifstream inputFile(blacklistFile);
    string line = "";
    int currentLine = 0;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            if (currentLine == index) {
                inputFile.close();
                return line;
            }
            currentLine++;
        }
        inputFile.close();
        // If the index was out of bounds
        cout << "Line index out of range: " << index << endl;
        return "";
    } else {
        cout << "Unable to open file for reading: " << blacklistFile << endl;
        return "";
    }
}