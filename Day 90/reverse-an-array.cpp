#include <iostream>
using namespace std;

// average
int main(){

    int arr[6] = {1, 2, 5, 6, 2, 3};
    int start = 0; int end = (sizeof(arr) / sizeof(arr[0])) - 1;

    for(int i=0; i<(sizeof(arr) / sizeof(arr[0])); i++){
        if(start < end){
            swap(arr[start], arr[end]);
            start++; end--;
        } else{break;}
    }

    return 0;
}

// more smarter;
int main(){

    int arr[6] = {1, 2, 5, 6, 2, 3};

    for(int start = 0, end = (sizeof(arr) / sizeof(arr[0])) - 1; start < end; start++, end--){
            swap(arr[start], arr[end]);
    }

    return 0;
}


// smartest way
int main(){

    int arr[6] = {1, 2, 5, 6, 2, 3};

    int start = 0, end = (sizeof(arr) / sizeof(arr[0])) - 1;

    while(start < end){
        swap(arr[start], arr[end]);
        start++; end--;
    }

    for(int i=0; i<(sizeof(arr) / sizeof(arr[0])); i++){
        cout << arr[i] << ", ";
    }

    return 0;
}