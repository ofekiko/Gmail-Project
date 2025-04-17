#include <string>
#include <iostream>
#include <fstream>
#include "FileFunction.h";
using namespace std;

void WriteURLtoFile(string& file, string& URL) {
    ofstream outputFile(file, ios::app);
    if (outputFile.is_open()) {
        outputFile << URL << endl;
        outputFile.close();
    } else {
        cout << "Unable to open file for writing: " << file << endl;
    }
}

string ReadLineFromFile(string& file, int index) {
    ifstream inputFile(file);
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
        cout << "Unable to open file for reading: " << file << endl;
        return "";
    }
}