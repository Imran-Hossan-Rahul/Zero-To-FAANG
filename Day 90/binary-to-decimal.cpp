#include <iostream>
using namespace std;



int main(){

    int n; cin >> n;
    int pow = 1;
    int ans = 0;

    while(n>0){
        ans += (n % 10) * pow;
        n /= 10;
        pow *= 2;
    }

    cout << ans << endl;

    return 0;
}