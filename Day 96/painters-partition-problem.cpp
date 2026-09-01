#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


bool isValid(vector<int>& nums, int n, int m, int maxTimeToPaint){                  // using referrance in function paramiter is better

    int man = 1, time = 0;

    for(int i=0; i<n; i++){
        if(time + nums[i] <= maxTimeToPaint){
            time += nums[i];
        } else{
            man++;
            time = nums[i];
        }
    }

    return man <= m;
}


int minTimeForPainting(vector<int>& nums, int n, int m){

    if(m > n){
        return -1;
    }

    int sum = 0, maxTime = INT_MIN;
    
    for(int i=0; i<n; i++){
        sum += nums[i];
        maxTime = max(nums[i], maxTime);
    }

    int start = maxTime, end = sum;

    int ans = -1;

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

    vector<int>nums = {10, 3, 13, 23, 98, 23};
    int n = nums.size(), m = 3;

    cout << minTimeForPainting(nums, n, m) << endl;

    return 0;
}