#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T, A, B;
	cin >> T;
	
	for(int i=0; i<T; i++){
	    
	    cin >> A >> B;
	    
	    if(A > B){
	        cout << ">" << "\n";
	    } else if(A < B){
	        cout << "<" << "\n";
	    } else {
	        cout << "=" << "\n";
	    }
	    
	}

}
