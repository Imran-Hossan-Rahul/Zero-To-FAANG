#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    int hard = false;

    for(int i=0; i<n; i++){
        int vote;
        cin >> vote;

        if(vote == 1){
            hard = true;
            break;
        }
    }

    if(hard){
        cout << "HARD\n";
    } else{
        cout << "EASY\n";
    }

    return 0;
}


//most clever approach
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int vote;
        cin >> vote;

        if(vote == 1){
            cout << "HARD\n";
            return 0;
        }
    }

    cout << "EASY\n";

    return 0;
}
