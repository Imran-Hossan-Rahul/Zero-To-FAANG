// Average Approach
class Solution {
public:
    string checkOddPairs(int A, int B, int C) {
        
        int sum = A + B + C;
        
        if((A % B % C == 0){
            return "YES";
        } else {
            return "NO";
        }
    }
};


// most optimal approach:
class Solution {
public:
    string checkOddPairs(int A, int B, int C) {
        return (A % 2 == B % 2 && B % 2 == C % 2) ? "NO" : "YES";
    }
};