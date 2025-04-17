#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <FileFunction.h>

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

        set <int> hashLoop(string& URL) {
            set<int> hashResultsIndex;
            for (int i = 0; i < this.hashFunctions.size()) {
                int index = repeatHashOnString(this.hashFunctions[i], URL);
                hashResultsIndex.insert(index);
            }
            return hashResultsIndex;
        }
  
          bool falsePositive(const string& url, istream& in)
        {
            string line;
            in.clear();           
            in.seekg(0);           
            while (getline(in, line))
            {
                if (url == line)  
                {
                    cout << "True\n";
                    break;
                }
                cout << "False\n";
            }
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
            set<int> hashResultsIndex = hashLoop(URL);
            for (int index : hashResultsIndex) {
                this.ptrToArr[index] = 1;
            }
            WriteURLtoFile(file, URL);
        }
  
          void checkURL (string& URL){
            int array[sizeOfArr] = hashLoop(url);
            for(int i = 0; i < sizeOfArr; i++){
                int bitIndex = array[i];
                if(ptrToArr[bitIndex] == 0){
                    cout << "False";
                    break;
                }
            }
            else{
                falsePositive(url, Blacklist);
            }
        }

};