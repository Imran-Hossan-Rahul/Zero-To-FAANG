#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int main(){

    vector<int>arr = {7,1,5,3,6,4};

    int bestBuy = INT_MAX;
    int maxProfit = 0;


    for(int i=0; i<arr.size(); i++){

        if(arr[i] > bestBuy){
            maxProfit = max(maxProfit, arr[i] - bestBuy);
        } else{
            bestBuy = min(arr[i], bestBuy);
        }
    }

    cout << maxProfit << endl;

    return 0;
}