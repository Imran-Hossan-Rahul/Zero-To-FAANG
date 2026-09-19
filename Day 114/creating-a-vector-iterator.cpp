#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    
    //normal iterator
    vector<int>:: iterator it;
    for(it = vec.begin(); it != vec.end(); it++){
        cout << *(it) << ", ";
    }
    cout << endl;

    // reverse iterator
    vector<int>:: reverse_iterator rit;
    for(rit = vec.rbegin(); rit != vec.rend(); rit++){
        cout << *(rit) << ", ";
    }
    cout << endl;

    //fastest way to create a vector iterator
    for(auto arit = vec.rbegin(); arit !=vec.rend(); arit++){
        cout << *(arit) << ", ";
    }
    cout << endl;
    
    return 0;
}