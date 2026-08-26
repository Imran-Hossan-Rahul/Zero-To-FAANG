#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSubSum = INT_MIN;
        int currSubSum = 0;

        for(int i=0; i<nums.size(); i++){
            currSubSum += nums[i];
            maxSubSum = max(currSubSum, maxSubSum);

            if(currSubSum < 0){
                currSubSum = 0;
            }
        }

        return maxSubSum;
    }
};