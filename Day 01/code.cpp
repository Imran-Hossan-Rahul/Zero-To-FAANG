#include <iostream>
#include <climits>
#include <vector>

using namespace std;



/* Brute Force Approach

double subArrMaxAvg(numstor<int>nums, int k, int n){
    double maxAvg = INT_MIN;
    for(int i=0; i<n; i++){
        double sum = 0;
        int count  = 0;
        double currAvg = 0;

        for(int j=i; j<n; j++){
            sum += nums[j];
            count++;
            
            if(count == k){
                currAvg = sum / count;
                maxAvg = max(currAvg, maxAvg);
                break;
            }
        }

        // Optimization
        if(n-i == k) {
            break;
        }
    }

    return maxAvg;
}
*/


double subArrMaxAvg(vector<int>nums, int k, int n){

    double maxAvg = INT_MIN;
    double start = 0;
    double sum  = 0;
    double currAvg = 0;
    double count = 0;

    for(int i=0; i<n; i++){

        count++;
        // cout << count;
        sum += nums[i];
        
        if(count == k){
            currAvg = sum / k;
            maxAvg = max(currAvg, maxAvg);
            // cout << "adfadsf";
        }
        

        if(count > k){
            // cout << "asdfdsaf";
            sum -= nums[start];
            currAvg = sum / k;
            maxAvg = max(currAvg, maxAvg);

            start++;
        }
    }

    return maxAvg;
}



int main(){
    int k = 4;
    // cout << "Please enter the integer: ";
    // cin >> k;                                       // k = 4
    vector<int>nums = {1,12,-5,-6,50,3};
    cout << subArrMaxAvg(nums, k, nums.size());
}