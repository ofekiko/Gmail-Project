#include "App.h"
#include <fstream>

void App::run() {
    string input;
    vector<int> numbers;
    ifstream in("Blacklist.txt");   

    // check if the input is by the correct format
    while (true) {
        getline(cin, input);
        stringstream ss(input);
        BloomFilter BF(input);
        addFunctionCommand.setBF(BF);
        string token;
        int number;
        bool isValid = true;
        numbers.clear();
        // check if the input is positive and in the correct format
        while (ss >> token) {
            stringstream numStream(token);
            if (numStream >> number && numStream.eof() && number > 0) {
                numbers.push_back(number);
            } else {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            break;
        }
    }
    cout << "Entered only valid numbers :)" << endl;
    string urlInput;
    cin >> urlInput;
    while (true) {
        int task = menu->nextCommand();
        try {
            commands[task]->execute();
        }
        catch(exception e){
            continue;
        }
    }
}