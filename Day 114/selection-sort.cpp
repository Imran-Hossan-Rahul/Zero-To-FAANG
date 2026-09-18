#include <iostream>
#include <vector>
using namespace std;


//Selection Ascending Sorting
void selectionSortAscending(vector<int>& arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        int smallestIdx = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[smallestIdx]){
                smallestIdx = j;
            }
        }

        if(smallestIdx != i){
            swap(arr[smallestIdx], arr[i]);
        }
    }
}


int main(){

    vector<int>arr = {5, 2, 4, 2, 1, 9, 8, 10};

    //selection ascending sorting
    selectionSortAscending(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}