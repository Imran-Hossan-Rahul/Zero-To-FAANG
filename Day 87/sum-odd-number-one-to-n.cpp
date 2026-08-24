#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int n; cin >> n;
    int oddSum = 0;

    for(int i=1; i<=n; i++){
        if(i % 2 != 0){
            oddSum += i;
        }
    }

    cout << oddSum << endl;

    return 0; 
}



// most optimal solution with big O(1) time complexity;

int main(){

    int n; cin >> n;

    int count = (n+1) / 2;

    cout << pow(count, 2) << endl;

    return 0;
    
}