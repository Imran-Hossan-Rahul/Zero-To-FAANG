#include <iostream>
using namespace std;


int main(){
    
int n; cin >> n;

    if(n<= 0){
        cout << "Not a power of two" << endl;
        return 0;             //must return 0 because it is the main function. so only return will cause error
    }
    
    while(n%2 == 0){
        n /= 2;
    }
    
    if(n==1){
        cout << true << endl;
        // cout << boolalpha << true << endl;      // using boolalpha will show excact true or false rather than showing 1 or 0 into the terminal;
    } else{
        cout << false << endl;
    }
    
    return 0;
}



// Most optimal solution
int main(){
    
int n; cin >> n;

if(n > 0 && (n & (n-1)) == 0){
    cout << boolalpha << true << endl;
} else{
    cout << boolalpha << false << endl;
}

return 0;
}
