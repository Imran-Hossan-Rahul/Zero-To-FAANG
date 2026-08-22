// Uses log10 for instant calculation; highly optimized for competitive programming. It uses a direct mathematical formula, meaning it runs in $O(1)$ time complexity. The CPU processes this type of raw mathematical operation extremely fast, and it requires zero extra memory allocation.
class Solution {
    public: {
        int totalDigit(int n){
            if(n == 0) return 1;
            return floor(log10(abs(n)))+1;
        }
    }
}

// Uses to_string().length(); the quickest to type and easiest to read. The to_string() function performs dynamic memory allocation in the background to convert the number into characters. This conversion process is much heavier and slower than a simple mathematical calculation.
class Solution {
    public: {
        int totalDigits(int n){
            if(n == 0) return 1;
            return to_string(abs(n)).length();
        }
    }
}

// Uses a basic while loop; the fundamental logic highly preferred in interviews.
int totalDigits(int n) {
    if (n == 0) return 1;

    n = abs(n);

    int count = 0;

    while (n) {
        count++;
        n /= 10;
    }

    return count;
}



/*
why shoud we use loop to find total digits?
Counting Digits in an Integer

Suppose we want to find how many digits a number has. For example:
12345 → 5 digits
123   → 3 digits
7     → 1 digit
1000  → 4 digits

There are two common approaches:
- Mathematical approach using log10()
- Loop approach using integer division

1. Using log10()
The mathematical formula for the number of digits of a positive integer n is: (int)log10(n) + 1. For example, if n = 12345, log10(12345) ≈ 4.0913. (int)4.0913 = 4. 4 + 1 = 5. So, int digits = (int)log10(n) + 1; gives 5.

Why does this formula work? Because powers of 10 define digit boundaries:
1        → 1 digit
10       → 2 digits
100      → 3 digits
1000     → 4 digits
10000    → 5 digits

Mathematically:
log10(1)    = 0
log10(10)   = 1
log10(100)  = 2
log10(1000) = 3

For any number between 100 and 999: 2 < log10(n) < 3. So (int)log10(n) will give 2, and adding 1 gives 3 digits.

2. What does (int) actually do?
Suppose double x = 4.91; If you do (int)x, you get 4. It truncates the decimal part. So (int)4.91 → 4, (int)7.99 → 7, (int)2.01 → 2. This is why (int)log10(n) + 1 works. For example, log10(500) ≈ 2.69897. (int)2.69897 → 2. 2 + 1 → 3 digits.

3. What is floor()?
floor() means: Return the greatest integer that is less than or equal to the number. Examples: floor(4.91) → 4, floor(7.99) → 7, floor(2.01) → 2. So for positive numbers, (int)x and floor(x) usually give the same result. For example, (int)4.91 and floor(4.91) both give 4. Therefore, (int)log10(n) + 1 and floor(log10(n)) + 1 are effectively doing the same thing for positive n.

4. Then what's the problem with log10()?
The important concept is floating-point precision. log10() returns a floating-point value, specifically a double. For example, log10(1000) mathematically should be exactly 3, because 10³ = 1000. But computers don't represent every real number perfectly using floating-point arithmetic. So, theoretically, a calculation that mathematically should produce 3.000000000000000 could internally be represented very slightly differently, such as 2.9999999999999996. The exact behavior depends on the implementation, floating-point arithmetic, library implementation, platform, etc.

5. Why can this become a problem?
This is where the important part comes in. Suppose mathematically log10(1000) = 3, but imagine the floating-point result is 2.9999999999999996. Now you do (int)log10(1000). Conceptually (int)2.9999999999999996 becomes 2. Then 2 + 1 gives 3. But 1000 actually has 4 digits. So the theoretical issue is: Expected 4, Potential result 3.

6. Why are powers of 10 important here?
Because they're exactly where the digit count changes. Look at:
9     → 1 digit
10    → 2 digits
99    → 2 digits
100   → 3 digits
999   → 3 digits
1000  → 4 digits
9999  → 4 digits
10000 → 5 digits

The boundaries are 10, 100, 1000, 10000, 100000, etc. And mathematically:
log10(10)    = 1
log10(100)   = 2
log10(1000)  = 3
log10(10000) = 4

If floating-point calculation gives a value slightly below the exact integer, like 3 → 2.999999999..., then casting or flooring gives the wrong integer. That's why the issue is especially relevant around these boundaries.

7. Does this mean log10() is bad?
No. This is very important. log10() is not bad. For many situations, this is perfectly fine: int digits = (int)log10(n) + 1; It is short and mathematically elegant. The point is simply that you're relying on floating-point mathematics, so there can theoretically be numerical precision concerns.

8. What about floor()?
You might think floor(log10(n)) + 1 is safer. But suppose log10(n) = 2.999999999999. Then floor(2.999999999999) still gives 2. So floor(log10(n)) + 1 doesn't solve the fundamental floating-point problem. The problem isn't whether you use (int) or floor(). The problem is that log10() itself is producing a floating-point result.

9. The Loop Approach
The alternative is to use integer division:
```cpp
int countDigits(int n) {
    if (n == 0) return 1;
    n = abs(n);
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}
```
Let's see what happens with n = 12345. The loop does:
12345 / 10 = 1234
1234  / 10 = 123
123   / 10 = 12
12    / 10 = 1
1     / 10 = 0
And every time we divide, count++; So count = 5.

10. Why does / 10 remove one digit?
Because integer division discards the decimal part. For example:
12345 / 10 = 1234
1234  / 10 = 123
123   / 10 = 12
12    / 10 = 1
1     / 10 = 0
Each division removes one digit from the right. This is a very important DSA concept.

11. Why is the loop approach more robust?
Because it uses integer arithmetic. There is no log10(), double, floating-point, rounding, floor(), or precision involved. You're simply doing n /= 10; which is deterministic integer arithmetic. So while (n) { count++; n /= 10; } is very reliable.

12. What about 0?
There's one special case. If n = 0, and you do while (n), the loop doesn't execute because 0 → false. But 0 has one digit. Therefore if (n == 0) return 1; is necessary. Similarly, with log10(), log10(0) is not valid for this purpose, so 0 must also be handled separately.

13. What about negative numbers?
Suppose n = -12345. We don't count the - sign as a digit. So we can do n = abs(n); Then -12345 → 12345, and count normally. That's why n = abs(n); is useful.

14. One important edge case: INT_MIN
There's actually a more advanced C++ issue with abs(n) if n is an int. For a typical 32-bit signed integer, INT_MIN = -2147483648 and INT_MAX = 2147483647. There is no positive int representation for 2147483648. So abs(INT_MIN) can cause an overflow/undefined-behavior-related issue depending on the context/implementation. For beginner-level DSA problems, this is usually outside the intended scope, but it's worth knowing.

15. Complexity
The loop approach while (n) { count++; n /= 10; } runs once per digit. For a number with d digits, Time = O(d). Since d ≈ log10(n), we often write Time = O(log n), Space = O(1). For a fixed-size C++ int, the maximum number of digits is bounded anyway, so practically it is extremely fast.

16. So which one should you use?
Mathematical/logarithmic approach:
`int digits = (int)log10(abs(n)) + 1;`
Advantages: Very short, mathematically elegant, fast, good when you specifically want a mathematical solution.
Disadvantages: Uses floating-point arithmetic, needs special handling for 0, can have theoretical precision concerns, less useful for learning digit-manipulation techniques.

Loop approach:
`int count = 0; while (n) { count++; n /= 10; }`
Advantages: Integer arithmetic only, no floating-point precision concerns, easy to understand, very reliable, teaches an important DSA technique, useful in many other digit problems.
Disadvantages: Slightly more code, technically performs multiple operations instead of a single library call.

17. For DSA, I'd recommend this
```cpp
class Solution {
public:
    int totalDigits(int n) {
        if (n == 0) return 1;
        n = abs(n);
        int count = 0;
        while (n) {
            count++;
            n /= 10;
        }
        return count;
    }
};
```
The important lesson isn't that log10() is wrong. The real lesson is: When you're dealing with discrete integer properties like digit count, integer arithmetic is often simpler and more robust than relying on floating-point calculations. And the loop technique you learned here is actually much more valuable for DSA because the same idea appears in reverse number, palindrome, sum of digits, Armstrong number, digit frequency, extracting digits, and many other problems.
*/