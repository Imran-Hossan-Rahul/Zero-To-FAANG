#include <iostream>
#include <vector>
#include <climits>
using namespace std;



bool isValid(vector<int>& nums, int n, int m, int maxAllocatedBooks){
    int student = 1, pages = 0;

    for(int i=0; i<n; i++){
            if(pages + nums[i] <= maxAllocatedBooks){
                pages += nums[i];
            } else{
                student++;
                pages = nums[i];
            }
    }

    return student <= m;
}



int allocateBooks(vector<int>& nums, int n, int m){

    if(n<m || n == 0 || m == 0) return -1;

    int maxElement = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(nums[i] > maxElement){
            maxElement = nums[i];
        }
    }

    int ans = -1;
    int start = maxElement, end = sum;
  
    while(start<=end){
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


    vector<int>nums = {13, 12, 23, 3, 4, 34};
    int n = nums.size();
    int m = 3;

    cout << allocateBooks(nums, n, m);

    return 0;
}