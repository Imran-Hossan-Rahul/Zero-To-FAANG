#include <iostream>
#include <vector>
using namespace std;



int main(){

    vector<int>nums = {3,3,7,7,10,11,11};
    int n = nums.size();
        
        if(n == 1) return nums[0];              //edge case

        int start = 0, end = n-1;

        while(start <= end){
            int mid = start + ((end-start) / 2);

            // cout << mid << " value: " << nums[mid] << endl;

            if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];        //edge case
            if(mid == n-1 && nums[mid] != nums[mid-1]) return nums[mid];      //edge case

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            if(mid % 2 == 0){
                if(nums[mid] == nums[mid-1]){
                    end = mid - 1;
                } else{
                    start = mid + 1;
                }
            } else{
                if(nums[mid] == nums[mid-1]){
                    start = mid + 1;
                } else{
                    end = mid - 1;
                }
            }
        }

    return 0;
}