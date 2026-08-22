#include <iostream>
using namespace std;

int main(){

    int t; long long n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << (n-1) / 2 << endl;
    }

    return 0;
}

/*
The Magic of Integer Division and Truncation in C++:
In C++, when you perform a division operation where both operands are integers (such as 7 / 2), the compiler strictly enforces the rule that the resulting value must also be an integer. Because no floating-point data types like float or double are involved in the calculation, the compiler resolves the decimal result of 3.5 through a process called truncation. Instead of rounding the number to the nearest whole value, truncation mercilessly chops off everything after the decimal point, discarding the .5 and leaving only the integer 3. This built-in behavior acts as a massive advantage for our candy distribution problem; since candies cannot be split into fractions, this automatic decimal dropping perfectly aligns with the exact number of valid distribution combinations (for 8 candies, the 3 valid ways are 7-1, 6-2, and 5-3), allowing a single mathematical formula to seamlessly handle both even and odd numbers.

*/


/*

You've got it exactly right! When an operation involves a smaller data type and a larger one, the compiler automatically upgrades the smaller type into the larger one to prevent any data loss; this automatic process is known as Implicit Type Conversion (or Type Promotion). On the other hand, when you as the programmer manually write code to force a data type to change—such as turning a float into an int or forcing a calculation to be long long to prevent overflow—that deliberate action is called Explicit Type Conversion (or Type Casting).

*/