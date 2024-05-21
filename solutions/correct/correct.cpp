#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
// Is the position worth <= than the brokers amount borrowed at the minimum price in the interval 
bool inline isLiqudated(int minPrice, int originalPrice, int leverage){
    return ((1.0 - (1.0 / double(leverage))) * (double) originalPrice) >= (double) minPrice;
}
//The main idea is to use a sparse table to answer min range queries in O(1)
// Note that '1 << number' is often used to get 2 ^ number 
int main(){
    int testCaseCnt;
    cin >> testCaseCnt;
    while (testCaseCnt--){
        int len;
        cin >> len;
        int tableHeight = ceil(log2(len)) + 1;
        vector<vector<int>> sparseTable(tableHeight, vector<int> (len, 0));
        for (int i = 0; i < len; i++){
            cin >> sparseTable[0][i];
        }
        // for each power of 2 in our sparse table
        // i = 0 already filled with the actual values
        for (int i = 1; i < tableHeight; i++){
            //end condition is such that the index + the current subinterval len (2^i) does not go out of bounds
            for (int j = 0; j + (1 << i) <= len; j++){
                int prevPow = i - 1;
                // take the values from the previous power of two row and combine them, the j index of the second argument starts at the first value not included in the first subinterval 
                sparseTable[i][j] = min(sparseTable[prevPow][j], sparseTable[prevPow][j + (1 << prevPow)]);
            }
        }
        int queries;
        cin >> queries;
        while (queries--){
            int startIndex, endIndex, leverage;
            cin >> startIndex >> endIndex >> leverage;
            int originalPrice = sparseTable[0][startIndex];
            // maximum exponent p such that 2^p is not bigger then the lenght of the current queried interval
            int subIntervalExp = floor(log2(endIndex - startIndex + 1));
            int subintervalLen = 1 << subIntervalExp;
            // if the interval is of size 2^x, then the same cell is passed as both arguments to the min function which is not a problem
            // otherwise there will be some overlap in the middle, but that does not change the result of minimum, being an overlap friendly function                                                              
            int intervalMin = min(sparseTable[subIntervalExp][startIndex], sparseTable[subIntervalExp][endIndex - subintervalLen + 1]);
            if (isLiqudated(intervalMin, originalPrice, leverage)) cout << "liquidated" << endl;
            else cout << "not-liquidated" << endl;
        }

    }
    return 0;
}