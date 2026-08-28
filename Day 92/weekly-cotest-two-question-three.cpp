#include <iostream>
using namespace std;



int main(){
    
    
    int n, px, py, qx, qy, rx, ry;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        
        cin >> px >> py >> qx >> qy;
        
        cout << 2 * qx - px << " " << 2 * qy - py << endl;
    }
    
    return 0;
}

