#include <iostream>
using namespace std;


int calcFac(int n){

    int fac = 1;

    for(int i=n; i>0; i--){
        fac *= i;
    }

    return fac;
}


int main(){

    int n; int r;
    cin >> n >> r;

    cout << calcFac(n) / ((calcFac(r)) * (calcFac(n-r))) << endl;

    return 0;
}