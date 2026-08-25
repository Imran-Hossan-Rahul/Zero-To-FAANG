#include <iostream>
using namespace std;


int main(){

    int num;
    cin >> num;
    
    int sum = 0;
    while (num){
        sum += num % 10;
        num /= 10;
    }
    
    cout << sum << "\n";

    return 0;
}