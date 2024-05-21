#include <bits/stdc++.h>
#define DATA_POINTS 100000
#define QUERIES 1000000
#define MAX_PRICE_MOVEMENT 15
using namespace std;
typedef long long int ll;

int main(){
    srand(time(NULL));
    //cout << 1 << endl;
    cout << DATA_POINTS << endl;
    int startPrice = 24034;
    int price = startPrice;
    for (int i = 0; i < DATA_POINTS; i++){
        //price = rand() % 100000;
        //price++;
        if (rand() % 2 == 0 and price - MAX_PRICE_MOVEMENT > 0){
            price -= rand() % MAX_PRICE_MOVEMENT;
        }
        else price += rand() % MAX_PRICE_MOVEMENT;
        cout << price << " ";
        
    }
    cout << endl;
    cout << QUERIES << endl;
    for (int i = 0; i < QUERIES; i++){
        int left = 0 + (rand() % (DATA_POINTS/10));
        int right = DATA_POINTS - 1 - (rand() % (DATA_POINTS/10));
        //int left = rand() % (DATA_POINTS - 1);
        //int right = left + 1 + rand() % (DATA_POINTS - left - 1);
        cout << left << " " << right << " " << (rand() % 250 + 1) << endl; 
    }
}