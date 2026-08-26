#include <iostream>
using namespace std;

// using two pointer
int main(){


    int arr[6] = {1, 2, 234, 52, 12, 5};

    int product = 1, sum = 0;

    int start = 0, end = (sizeof(arr) / sizeof(arr[0])) - 1;

    while(start <= end){

        if(start == end){
            product *= arr[start];
            sum += arr[end];
        } else{
            product *= (arr[start] * arr[end]);
            sum += (arr[start] + arr[end]); 
        }

        start++; end--;

    }


    cout << "The products is: " << product << endl << "The sum is: " << sum << endl; 

    return 0;
}


// using normal for loop

int main(){

    int arr[6] = {2, 4, 5, 23, 52, 12};

    int sum = 0, product = 1;

    for(int i=0; i<sizeof(arr) / sizeof(arr[0]); i++){
        sum += arr[i];
        product *= arr[i];
    }


    cout << sum << ", " << product << endl;

    return 0;
}