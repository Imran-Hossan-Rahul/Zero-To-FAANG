#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int>nums = {4,5,6,7,0,1,2};                       //target = 0;

    int target = 0;
    int n = nums.size();
    int start = 0, end = n - 1;

    if(n == 1){
        if(nums[0] == target){
            return 0;
        } else{
            return -1;
        }
    };

    while(start <= end){
        int mid = start + ((end-start) / 2);
        

        if(target == nums[mid]){
            cout << mid << endl;
            return mid;
        }

        if(nums[start] <= nums[mid]){
            if(nums[start] <= target && nums[mid] >= target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        } else{
            if(nums[mid] <= target && nums[end] >= target){
                start = mid + 1;
            } else{
                end = mid - 1;
            }
        }

    }

    cout << "-1" << endl;

    return 0;
}