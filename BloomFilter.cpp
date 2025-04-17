#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class BloomFilter{
    private:
        const int sizeOfArr;
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

        set <int> hashloop(string& URL) {
            set<int> hashResultsIndex;
            for (int i = 0; i < this.hashFunctions.size()) {
                int index = repeatHashOnString(this.hashFunctions[i], URL);
                hashResultsIndex.insert(index);
            }
            return hashResultsIndex;
        }

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
            set<int> hashResultsIndex = hashloop(URL);
            for (int index : hashResultsIndex) {
                this.ptrToArr[index] = 1;
            }
            
        }

        void checkURL (string& URL){}
};