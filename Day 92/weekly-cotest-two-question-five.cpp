#include <iostream>
using namespace std;


int main(){

    int n, k;
    int maxAnd = 0, maxOr = 0, maxXor = 0;
    cin >> n >> k;

    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if((i&j) < k && (i&j) > maxAnd){
                maxAnd = i&j;
            }

            if((i|j) < k && (i|j) > maxOr){
                maxOr = i|j;
            }

            if((i^j) < k && (i^j) > maxXor){
                maxXor = i^j;
            }
        }
    }

    cout << maxAnd << endl;
    cout << maxOr << endl;
    cout << maxXor << endl;

    return 0;
}