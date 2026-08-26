#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;



int main(){

    int arr[5] = {5, 2, 2, 2, 23};
    int maxNum = INT_MIN, maxIdx = 0, minNum = INT_MAX, minIdx = 0;               //minIdx and maxIdx should be initialized with the value of 0 is the best practice to avoid unusual behaviour;


    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){

        if(maxNum < arr[i]){
            maxNum = arr[i];
            maxIdx = i;
        }
        if(minNum > arr[i]){
            minNum = arr[i];
            minIdx = i;
        }
    }

    swap(arr[maxIdx], arr[minIdx]);

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << ", ";
    }

    cout << endl;


    return 0;
}