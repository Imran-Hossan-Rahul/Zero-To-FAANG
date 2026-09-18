#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Sorting with brute force approach; Time complexity 0(nlogn), Space Complexity 0(1);
void sortBruteForce(vector<int>& arr){
    sort(arr.begin(), arr.end());
}


//Sorting with slightly better approach;
int sortSlighlyBetter(vector<int>& arr, int n){

    int count0 = 0, count1 = 0, count2 = 0, idx = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            count0++;
        } else if(arr[i] == 1){
            count1++;
        } else{
            count2++;
        }
    }

    //placing the value with their count;
    for(int i=0; i<count0; i++){
        arr[idx++] = 0;
    }
    for(int i=0; i<count1; i++){
        arr[idx++] = 1;
    }
    for(int i=0; i<count2; i++){
        arr[idx++] = 2;
    }
}


int main(){


    vector<int>arr = {2,0,2,1,1,0};
    int n = arr.size();

    //Sort with brute force
    // sortBruteForce(arr);

    //Sort with slightly better approach
    sortSlighlyBetter(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}