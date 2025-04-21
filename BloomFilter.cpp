#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include "FileFunction.h"
#include "Blacklist.txt"

using namespace std;

class BloomFilter{
    private:
        int sizeOfArr;
        int* ptrToArr;
        vector <int> hashFunctions;

        int repeatHashOnString(int n, const string& input) {
            hash<string> hasher;
            string current = input;
            size_t hashValue = 0;
        
            for (int i = 0; i < n; ++i) {
                hashValue = hasher(current);
                current = to_string(hashValue);
            }
        
            return static_cast<int>(hashValue % sizeOfArr);
        }

        int* hashLoop(string& URL) {
            int hashResultsIndex[sizeOfArr] = {0};
            
            for (int i = 0; i < hashFunctions.size(); i++) 
            {
                int index = repeatHashOnString(hashFunctions[i], URL);
                hashResultsIndex[i] = index;
            }
            return hashResultsIndex;
        }
  
        // void falsePositive(const string& url)
        // {
        //     string blacklistFile = "Blacklist.txt";
        //     ifstream inputFile(blacklistFile);
        //     string line;
        //     blacklistFile.clear();           
        //     blacklistFile.seekg(0);           
        //     while (getline(blacklistFile, line))
        //     {
        //         if (url == line)  
        //         {
        //             cout << "true\n";
        //             break;
        //         }
        //         cout << "false\n";
        //     }
        // }

    public:
        BloomFilter (string& input){
            stringstream ss(input);
            int number;
        
            while (ss >> number) {
                hashFunctions.push_back(number);
            }
        
            sizeOfArr = hashFunctions.front();
            hashFunctions.erase(hashFunctions.begin());
            int arrayOfFilter[sizeOfArr] = {0};
            ptrToArr = arrayOfFilter;
        }

        void addURL (string& URL){
            int* hashResultsIndex = hashLoop(URL);
            for (int i = 0; i < sizeOfArr; i++) {
                ptrToArr[hashResultsIndex[i]] = 1;
            }
            WriteURLtoFile(URL);
        }
  
        void checkURL (string& URL){
            int* hashResultsIndex = hashLoop(URL);
            for(int i = 0; i < sizeOfArr; i++){
                int bitIndex = hashResultsIndex[i];
                if(ptrToArr[bitIndex] == 0){
                    cout << "false";
                    break;
                } 
            }
            
            // falsePositive(URL);
            
        }

};