#include <iostream>
#include <vector>
using namespace std;


int main(){

    long long N; cin >> N;

    vector<int>arr(N);

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    long long sum = 0;
    
    for(int i=0; i<N; i++){
        sum += arr[i];
    }

    if(sum % 24 == 0){
        cout << sum << endl;
    } else{
        cout << 24 * ((sum / 24) + 1) << endl;
    }

    return 0;
}