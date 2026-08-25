#include <iostream>
using namespace std;


bool fp(int n){

    if(n <= 1){
        return false;
    }
    
    bool prime = true;

    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            prime = false;
            break;
        }
    }

    return prime;
}


int main(){

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        if(fp(i)){
            cout << i << ", ";
        }
    }

    return 0;
}