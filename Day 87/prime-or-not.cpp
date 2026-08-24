#include <iostream>
using namespace std;

int main(){

    int n; 
    cin >> n;
    int currNum = 2;
    int prime = true;

    while(currNum * currNum <= n) {
        if(n % currNum == 0){ 
            prime = false;    
            break;            
        }
        currNum++;
    }


    prime == true ? cout << "prime" : cout << "false";

    return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

