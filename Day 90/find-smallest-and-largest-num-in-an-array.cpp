#include <iostream>
#include <climits>
#include <algorithm>               // for using min() and max() function
using namespace std;

//largst
int main(){
    int arr[8] = {2, 3, 5, 1, 2, 5, 7, 10};
    int maxNum = INT_MIN;

    for(int i=0; i<(sizeof(arr) / sizeof(arr[i])); i++){

        maxNum = max(arr[i], maxNum);

    }

    cout << maxNum << endl;

    return 0;
}


//smallest
int main(){
    int arr[8] = {2, 3, 5, 1, 2, 5, 7, 10};
    int minNum = INT_MAX;

    for(int i=0; i<(sizeof(arr) / sizeof(arr[i])); i++){

        minNum = min(arr[i], minNum);

    }

    cout << minNum << endl;

    return 0;
}