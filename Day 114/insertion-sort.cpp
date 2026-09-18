#include <iostream>
#include <vector>
using namespace std;


//Ascending insertion sort
void insertionAscendingSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int prev = i-1, curr = arr[i];

        while(prev >= 0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}


//Descending insertion sort
void insertionDescendingSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int prev = i-1, curr = arr[i];

        while(prev >= 0 && arr[prev] < curr){
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}


int main(){

    
    vector<int>arr = {4, 1, 5, 2, 3};

    // Insertion ascending sorting
    insertionAscendingSort(arr);

    cout << "Ascending Sorting" << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    // Insertion Descending sorting
    insertionDescendingSort(arr);
    
    cout << "Descending Sorting" << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;


    return 0;
}