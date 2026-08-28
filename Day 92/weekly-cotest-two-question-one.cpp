#include <iostream>
#include <iomanip>
using namespace std;



int main(){

    int num1, num2;
    float num3, num4;

    cin >> num1 >> num2;
    cin >> num3 >> num4;

    cout << num1 + num2 << " " << num1 - num2 << "\n";
    cout << fixed << setprecision(1) << num3 + num4 << " " << num3 - num4 << "\n";
    return 0;
}