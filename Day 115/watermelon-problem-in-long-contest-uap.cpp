#include <iostream>
using namespace std;


int main(){


    int w;
    cin >> w;

    if(w > 3 && w % 2 == 0){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }

    return 0;
}