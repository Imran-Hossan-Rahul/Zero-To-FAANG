#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


bool isValid(vector<int>& nums, int n, int m, int maxBook){
    int pages = 0, student = 1;

    for(int i=0; i<n; i++){
        if(nums[i] + pages <= maxBook){
            pages += nums[i];
        } else{
            student++;
            pages = nums[i];
        }
    }

    return student <= m;
}


int allocateBooks(vector<int>& nums, int n, int m){

    if(m > n){
        return - 1;
    }

    int sum = 0, maxVal = INT_MIN;

    for(int i=0; i<n; i++){
        sum += nums[i];
        maxVal = max(nums[i], maxVal);
    }

    int start = maxVal, end = sum, ans = -1;
    while(start <= end){
        int mid = start + ((end-start) / 2);

        if(isValid(nums, n, m, mid)){
            ans = mid;
            end = mid - 1;
        } else{
            start = mid + 1;
        }
    }

    return ans;
}


int main(){

    vector<int>nums = {444, 3, 4, 34};
    int n = nums.size();
    int m = 2;

    cout << allocateBooks(nums, n, m) << endl;
}