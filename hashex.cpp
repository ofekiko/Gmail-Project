#include <iostream>
#include <functional>
#include <string>
using namespace std;

int repeatHashOnString(int n, string& input) {
    hash<string> hasher;
    int sizeOfArray = 256;
    string current = input;
    size_t hashValue = hasher(current);    

    for (int i = 0; i < n; ++i) {
        current = to_string(hashValue);           
        cout << "Hash " << i + 1 << ": " << current << endl;
    }
    return static_cast<int>(hashValue % sizeOfArray); 
}

int main(){
    string s = NULL;
    repeatHashOnString(4, s);
    //repeatHashOnString(2, s);
    return 0;
}
