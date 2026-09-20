









// skipped











#include <iostream>
using namespace std;


int main(){


    int t, a, b; cin >> t;

    for(int i=0; i<t; i++){
        int count = 0;
        cin >> a; cin >> b;
 
        if(a < b){
            cout << b - 1 << endl;
            continue;
        } else{
            while(a % b != 0){
            a++; count++;
            }
            cout << count << endl;
        }
    }

    return 0;
}