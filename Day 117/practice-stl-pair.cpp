#include <iostream>
#include <vector>
using namespace std;


int main(){

    pair<int, int>p1 = {2, 5};
    pair<int, string>p2 = {3, "nothing"};
    pair<char, char>p3 = {'C', 'D'};
    pair<pair<int, string>, pair<int, int>> p4 = {{4, "nothing"}, {3, 5}};
    

    vector<pair<pair<int, string>, pair<int, int>>>vec ={{{4, "nothing"}, {3, 5}}, {{4, "nothing"}, {3, 5}}};

    return 0;
}