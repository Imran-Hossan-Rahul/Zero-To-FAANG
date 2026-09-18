#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isPossible(vector<int>& arr, int N, int C, int minAllowedDistance){
    int cows = 1, lastStallPosition = arr[0];

    for(int i=1; i<N; i++){

       if(arr[i] - lastStallPosition >= minAllowedDistance){
            lastStallPosition = arr[i];
            cows++;
       }

       if(cows == C){
            return true;
       }

    }

    return false;
}


int aggressiveCow(vector<int>& arr, int N, int C){

    sort(arr.begin(), arr.end());

    int lowest = 1, highest = arr[N-1] - arr[0];

    int ans = -1;

    while(lowest <= highest){
        int mid = lowest + ((highest - lowest) / 2);

        if(isPossible(arr, N, C, mid)){
            ans = mid;
            lowest = mid + 1;
        } else{
            highest = mid - 1;
        }
    }

    return ans;
}


int main(){
    
    vector<int> arr = {1, 2, 8, 4, 9};
    int N = 5, C = 3;

    cout << aggressiveCow(arr, N, C);

    return 0;
}