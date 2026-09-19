#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void nextPermutation(vector<int>& nums, int n){
    int pivit = -1;
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            pivit = i;
            break;
        }
    }

    //if array is sorted in descending order
    if(pivit == -1){
        int start = 0, end = n-1;
        while(start <= end){
            swap(nums[start], nums[end]);
            start++; end--;
        }
        return;
    }

    //finding the rightmost element
    for(int i=n-1; i>pivit; i--){
        if(nums[i] > nums[pivit]){
           swap(nums[i], nums[pivit]);
           break;
        }      
    }

    //reverse from pivit+1 to n-1
    int start = pivit + 1, end = n - 1;
    while(start <= end){
        swap(nums[start], nums[end]);
        start++; end--;
    }

}


int main(){


    vector<int>nums = {1,2,3};
    int n = nums.size();

    //Using Next Permutation
    nextPermutation(nums, n);
    for(int i=0; i<n; i++){
        cout << nums[i] << ", ";
    }
    cout << endl;


    return 0;
}