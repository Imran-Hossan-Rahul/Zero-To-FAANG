#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void sortBruteForce(vector<int>& arr){
    sort(arr.begin(), arr.end());
}


int main(){


    vector<int>arr = {2,0,2,1,1,0};
    int n = arr.size();

    //Sort with brute force
    sortBruteForce(arr);
    for(int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}