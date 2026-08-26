#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int distinctCount(vector<int>arr){

    int count = 0;
    int previousVal = 0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){

        if(arr[i] != previousVal){
            count++;
        }

        previousVal = arr[i];
        
    }

    return count;
}

int findIdx(vector<int>nums, int target){

    int idx;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target){
            idx = i;
            return idx;
        }
    }

    return idx;
}



int main (){

    int t; cin >> t;
    for(int tc=0; tc<t; tc++){

        int n; cin >> n;

        int opCount = 0;

        vector<int>arr(n);

        for(int i=0; i<n;i++){
            cin >> arr[i];
        }

        int max_val = *max_element(arr.begin(), arr.end());
        int min_val = *min_element(arr.begin(), arr.end());
        int distinct_val = distinctCount(arr);


        // if(max_val - min_val >= distinct_val){
        //     arr.erase(arr.begin() + findIdx(arr, max_val));
        //     opCount++;
        // } else{
        //     cout << opCount << ".\n";
        // }


        while(max_val - min_val >= distinct_val){
            arr.erase(arr.begin() + findIdx(arr, max_val));
            opCount++;
        }


        cout << opCount << ".\n";
    }


    return 0;
}