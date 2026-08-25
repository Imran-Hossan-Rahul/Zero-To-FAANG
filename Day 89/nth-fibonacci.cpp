// for finding the excact answer

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(int n){

    double fibonacci = (1.0/sqrt(5.0)) * ((pow(((1.0 + sqrt(5.0)) / 2.0), (double)n)) - (pow(((1.0 - sqrt(5.0)) / 2.0), (double)n)));

    return fibonacci;
}


int main(){

    int n;
    cin >> n;

    cout << fixed << setprecision(15) << f(n) << endl;

    return 0;
}




/*


1. Why use double instead of float?
Both float and double are used to store decimal numbers, but the main difference lies in their memory size and precision. A float takes up 4 bytes of memory and can accurately represent numbers up to 6 or 7 decimal places. On the other hand, a double takes up 8 bytes of memory and provides double the precision, accurately representing numbers up to 15 or 16 decimal places. Because Binet's formula involves irrational numbers like the square root of 5 and calculating large powers using pow(), the calculations get very complex and heavily rely on long decimal values. If you use a float, the computer will start dropping those extra decimal digits as the numbers grow, which leads to a loss of accuracy (known as precision loss). Using double ensures the mathematical calculations remain as accurate and close to the true value as possible, which is why it is the standard choice for scientific and mathematical operations in C++.

2. What would happen if you used long long?
The long long data type is strictly for integers, meaning it can only store whole numbers. It has absolutely no capacity to store fractions or decimal points. If you were to store the result of this formula in a long long variable, C++ would automatically perform something called "truncation." This means it would aggressively chop off everything after the decimal point. For example, if the exact calculation yielded a true value of 7.999999, storing it in a long long would instantly strip away the decimals and turn it into a flat 7. By using double, we prevent this truncation and preserve the exact true value you are looking for.

3. Why write 5.0, 1.0, and 2.0 instead of just 5, 1, and 2?
This is one of the most common traps in C++. Whenever you perform math using only whole numbers (integers), C++ assumes you want an integer as the result. If you write 1 / 2 in C++, the compiler will not give you 0.5; instead, it will chop off the decimal and give you 0. While it is true that using functions like sqrt(5) forces C++ to upgrade the surrounding numbers to decimals automatically (a process called type promotion), relying on this can sometimes lead to unexpected bugs. By explicitly writing 1.0, 2.0, and 5.0, you are giving the compiler a strict command from the very beginning: "Treat all of these numbers as floating-point decimals, and do not perform any integer division."

4. How do you handle the integer n (like converting 3 to 3.0)?
Since n is taken as an integer (e.g., 3), you might wonder how it becomes 3.0 for the pow() function. In C++, the pow() function natively expects double values. When you pass an integer n into it, the compiler automatically converts it into a decimal behind the scenes—a feature known as Implicit Type Conversion. However, if you want to be completely explicit and write bulletproof code, you can manually convert it using Type Casting. You can do this in a few ways:

C-style casting: Simply write (double)n before the variable.

Math trick: Multiply n by a decimal, like n * 1.0.

Modern C++ approach: Use static_cast<double>(n).

By writing your code as pow(..., (double)n), you leave absolutely no room for error, ensuring the entire formula strictly operates using decimal arithmetic from start to finish.


*/