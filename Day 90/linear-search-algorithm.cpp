#include <iostream>
using namespace std;


int main(){

    int n; cin >> n;
    int arr[6] = {2, 5, 1, 63, 92, 12};

    for(int i=0; i<(sizeof(arr)) / sizeof(arr[0]); i++){
        if(arr[i] == n){
            cout << "The index is: " << i << endl;
            return 0;
        }
    }

    cout << "Number not found" << endl;
    return 0;
}