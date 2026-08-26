#include <iostream>
#include <climits>
using namespace std;


int main(){

    int arr[8] = {1,2,5,3,6,2,9,2};

    int smIndex, larIndex;
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i=0; i<(sizeof(arr) / sizeof(arr[0])); i++){

        if(arr[i] < smallest ){smallest = arr[i]; smIndex = i;}
        if(arr[i] > largest ){largest = arr[i]; larIndex = i;}
    }

    cout << "Smallest Index = " << smIndex << "\n" << "Largest Index = " << larIndex << endl;

    return 0;
}