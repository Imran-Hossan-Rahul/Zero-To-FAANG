#include <iostream>
#include <vector>
using namespace std;


//Bubble Sort Ascending
void bubbleSortAscending(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        bool swaped = false;                   //optimization
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped) return;
    }
}


//Bubble Sort Descending
void bubbleSortDescending(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        bool swaped = false;                   //optimization
        for(int j=0; j<n-i-1; j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped) return;
    }
}


int main(){


    vector<int>arr = {5, 2, 4, 2, 1, 9, 8, 10};

    //Ascending Sorting
    bubbleSortAscending(arr);

    cout << "Ascending Sorting" << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;


    //Descending Sorting
    bubbleSortDescending(arr);
    
    cout << "Ascending Sorting" << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}