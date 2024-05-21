#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;


int main(){
    int testCaseCnt;
    cin >> testCaseCnt;
    while (testCaseCnt--){
        int len;
        cin >> len;
        vector<int> prices(len);
        for (int i = 0; i < len; i++){
            cin >> prices[i];
        }
        int queries;
        cin >> queries;
        while (queries--){
            int startIndex, endIndex, leverage;
            cin >> startIndex >> endIndex >> leverage;
            int originalPrice = prices[startIndex];
            bool liqudiated = false;
            for (int i = startIndex; i <= endIndex; i++){
                double ratio = (double)prices[i] / (double)originalPrice;
                if ((ratio + 1.0 / (double) leverage) <= 1.0 ) {
                    liqudiated = true;
                    break;
                }
            }
            if (liqudiated) cout << "liquidated" << endl;
            else cout << "not-liquidated" << endl;
        }

    }
    return 0;
}