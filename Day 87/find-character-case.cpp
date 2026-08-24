#include <iostream>
using namespace std;

int main(){

    char c;
    cin >> c;

    if(c >= 'A' && c <= 'Z'){
        cout << "Upper" << endl;
    } else{
        cout << "Lower" << endl;
    }

    return 0;
}


int main(){

    char c;
    cin >> c;

    if(c >= 65 && c <= 90){
        cout << "Upper" << endl;
    } else{
        cout << "Lower" << endl;
    }

    return 0;
}

int main(){

    char c;
    cin >> c;

    if(c >= 97 && c <= 122){
        cout << "Lower" << endl;
    } else{
        cout << "Upper" << endl;
    }

    return 0;
}