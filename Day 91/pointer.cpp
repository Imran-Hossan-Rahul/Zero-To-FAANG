#include <iostream>
using namespace std;


int main(){

    int another = 23;
    
    int* a = &another;

    int** ptr1 = &a;   cout << ptr1 << ", " << *ptr1 << endl;         //  0x61ff08, 5

    int*** ptr2 = &ptr1;   cout << ptr2 << ", " << ***ptr2 << endl;

    return 0;
}