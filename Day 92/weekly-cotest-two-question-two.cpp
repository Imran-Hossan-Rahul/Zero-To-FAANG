#include <iostream>
#include <string>
using namespace std;


int main(){


    char ch; string s; string sen;

    cin >> ch;
    cin >> s;

    cin.ignore();        // for ignoring /n of previous cin

    getline(cin, sen);

    cout << ch << endl;
    cout << s << endl;
    cout << sen << endl;


    return 0;
}