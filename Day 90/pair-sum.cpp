#include <iostream>
#include <vector>
using namespace std;


// brute force
int main(){

    vector<int>nums = {1, 2, 3, 5, 62, 34, 1};
    vector<int>ans;

    int target = 8;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            }
        }
    }

    return 0;
}



//optimized approach using two pointers;       🚨Array must be sorted in ascending or descending order🚨
int main(){

    vector<int>nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int>ans;

    int target = 8;
    int start = 0, end = nums.size() - 1;

    while(start < end){
        if(nums[start] + nums[end] > target){
            end--;
        } else if(nums[start] + nums[end] < target){
            start++;
        } else{
            ans.push_back(nums[start]);
            ans.push_back(nums[end]);
            break;
        }
    }

    return 0;
}