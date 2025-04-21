#include <gtest/gtest.h>

using namespace std;

#define NUM_OF_ARRAYS 2
int *arr[NUM_OF_ARRAYS];
int *hashTablePtr;
int *bloomFilterPtr;
//array of number of hash tables and the size of 
int arrayHash[3] = {8,1,2};
//array of the filter. the 0 and 1
int arrayFilter [8]= {0};
bool checkURL (int *array [NUM_OF_ARRAYS], string& URL);

int repeatHashOnString(int n, string& input);

TEST(CheckIfBlacklisted,SenityTest){
    arr[0] = hashTablePtr;
    arr[1] = bloomFilterPtr;
    hashTablePtr = arrayHash;
    bloomFilterPtr = arrayFilter;
    //marked ex1 as blacklisted
    string ex1 = "“www.example.com0";
    string ex2 = "“www.example.com1";
    bloomFilterPtr[1] = 1;
    bloomFilterPtr[2] = 1;
    EXPECT_EQ(checkURL(arr,ex1), true);
    EXPECT_EQ(checkURL(arr,ex2), false);
}
TEST(CheckIfBlacklisted,EmptyString){
    arr[0] = hashTablePtr;
    arr[1] = bloomFilterPtr;
    hashTablePtr = arrayHash;
    bloomFilterPtr = arrayFilter;
    string URL = NULL;
    EXPECT_THROW(checkURL(arr,URL),exception);
}
TEST(CheckIfBlacklisted,checkIfSaved){
    arr[0] = hashTablePtr;
    arr[1] = bloomFilterPtr;
    hashTablePtr = arrayHash;
    bloomFilterPtr = arrayFilter;
    string ex1 = "“www.example.com0";
    EXPECT_EQ(checkURL(arr,ex1), true);
}
int main(){
}
