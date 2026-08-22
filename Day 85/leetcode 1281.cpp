//Given an integer number n, return the difference between the product of its digits and the sum of its digits.

class Solution {
public:
    int subtractProductAndSum(int n) {

        /*
        if constraints says 0 <= n <= 10^5 then:
        if(n == 0) return 0;
        */
        
        int pro = 1;
        int sum = 0;
        while(n > 0){
            pro *= n % 10;
            sum += n % 10;

            n /= 10;
        }

        return pro - sum;
    }
};


class Solution {
public:
    int subtractProductAndSum(int n) {

        /*
        if constraints says 0 <= n <= 10^5 then:
        if(n == 0) return 0;
        */

        int pro = 1;
        int sum = 0;
        while(n > 0){
            pro *= n % 10;
            sum += n % 10;

            n /= 10;
        }

        return pro - sum;
    }
};



/*

Why and how 2nd solution is better than 1st solution though first one has a better time complexity?

Ans: The primary reason the second code stands out as the better approach is its readability. In the first code, the same mathematical operation—the modulo operation (n % 10)—is calculated twice. This makes the code look slightly cluttered and forces anyone reading it to process the same logic multiple times. In contrast, the second code introduces a separate variable named currDig to extract and store the last digit beforehand. This simple change makes the code look much cleaner and highly professional. It becomes instantly clear to any developer that the same extracted digit is being reused for both multiplication and addition, making the core logic transparent and much easier to modify or debug in the future.

The second reason involves computational performance and optimization. In programming, calculating the modulo or remainder (%) is a relatively expensive operation that consumes more processor time and energy compared to basic addition or subtraction. In the first code, the processor has to perform this exact same modulo calculation twice during every single iteration of the loop, which is computationally wasteful. The second code solves this by performing the calculation just once and saving the result in a variable, thereby significantly reducing the workload on the processor. While it is true that modern compilers are smart enough to automatically optimize the first code behind the scenes, consciously writing inherently optimized and resource-efficient code is always a hallmark of a good programmer and a standard industry practice.

*/