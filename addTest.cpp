// #include <gtest/gtest.h>
// #include <string>
// #include <functional>
// using namespace std;

// #define SIZE 100
// #define numOfArrays 2

// int arrayHash[SIZE] = {0};
// int arrayFilter[SIZE] = {0};

// int* hashTablePtr = arrayHash;
// int* bloomFilterPtr = arrayFilter;
// int* arr[numOfArrays] = {hashTablePtr, bloomFilterPtr};

// void addFunc(int* array[numOfArrays], const string& url) {
//     int h = repeatHashOnString(8, url);
//     array[1][h] = 1;
// }

// int repeatHashOnString(int n, const string& input) {
//     hash<string> hasher;
//     string current = input;
//     size_t hashValue = 0;

//     for (int i = 0; i < n; ++i) {
//         hashValue = hasher(current);
//         current = to_string(hashValue);
//     }

//     return static_cast<int>(hashValue % SIZE);
// }

// TEST(addFunctionTest, correctAdding) {
//     string url = "www.correctAdding.co.il";
//     int numberOfHash = 8;
//     arr[0][0] = numberOfHash;
//     int h = repeatHashOnString(numberOfHash, url);
//     addFunc(arr, url);
//     EXPECT_EQ(arr[1][h], 1); 
// }

// TEST(addFunctionTest, correctAddingWith2Hash){
//     string url = "www.correctAdding2.co.il";
//     const int size = 20;
//     int x = 8;
//     int y = 10;
//     arr[0][0] = x;
//     arr[0][1] = y;
//     int h1 = repeatHashOnString(x, url);
//     int h2 = repeatHashOnString(y, url);
//     addFunc(arr, url);
//     EXPECT_EQ(arr[1][h1], 1);
//     EXPECT_EQ(arr[1][h2], 1);
// }

// TEST(addFunctionTest, uncorrectAdding){
//     string url = NULL;
//     int x = 8;
//     arr[0][0] = x;
//     int h = repeatHashOnString(x, url);
//     EXPECT_THROW(addFunc(arr, url), exception);
// }

// // void add(string& url, int index);

// // void add2(string& url, int* array);

// // int hashURL(string);

// // TEST(addFunctionTest, addURL){
// //     string url = "www.shirel.co.il";
// //     int input[8] = {1,2,3,4,5,6,7,8};
// //     int blacklist[8] = {0};
// //     for(int i = 0; i < 8; i++){
// //         blacklist[input[i]*hashURL(url)] = 1;
// //     }
// //     int index = hashURL(url);
// //     arr[index] = 0;
// //     add(url, index);
// //     EXPECT_EQ(arr[index], 1);
// // }

// // TEST(addFunctionTest, addURL2){
// //     string url = "www.shirel.co.il";
// //     int index = hashURL(url);
// //     arr[index] = 0;
// //     add(url, index);
// //     EXPECT_EQ(arr[index], 1);
// // }

// // TEST(addFunctionTest, addURL3){
// //     string url = "www.shirel.co.il";
// //     int index = hashURL(url);
// //     arr[index] = 0;
// //     add(url, index);
// //     EXPECT_EQ(arr[index], 1);
// // }

// // TEST(addFunctionTest, addURL4){
// //     string url = "www.shirel.co.il";
// //     add(url, 1);
// //     int index = hashURL(url);
// //     EXPECT_EQ(arr[index], 1);
// // }