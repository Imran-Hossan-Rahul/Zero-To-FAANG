#include <iostream>
using namespace std;


int main(){

    int n; cin >> n;
    int ans = 0;
    int pow = 1;
    while(n > 0){

        ans += (n % 2) * pow;
        n /= 2;
        pow *= 10;

    }

    cout << ans << endl;

    return 0;
}