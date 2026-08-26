#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force approach;
// int main(){
//     vector<int>nums = {2,2,1,1,1,2,2};
//     int freq = 1;
//     int majorElement;

//     if(nums.size() == 1) {
//         cout << nums[0] << endl;
//         return 0;
//     }

//     for(int i=0; i<nums.size(); i++){

//         majorElement = nums[i];
//         freq = 1;

//         for(int j=i+1; j<nums.size(); j++){
//             if(nums[i] == nums[j]){
//                 freq++;
//                 if(freq > nums.size() / 2){
//                     cout << majorElement << endl;
//                     return 0;
//                 }
//             }
//         }
//     }

//     return 0;
// }


//slightly optimized approach;
// int main(){

//     vector<int>nums = {2,2,1,1,1,2,2};

//     sort(nums.begin(), nums.end());

//     int ans, freq = 0;

//     for(int i=0; i<nums.size(); i++){
//         if(freq == 0){
//             ans = nums[i];
//         }
//         if(nums[i] == ans){

//             freq++;

//             if(freq > nums.size() / 2) {
//                 cout << ans << endl;
//                 return 0;
//             }
//         } else{                                             // did mistake first time here
//             ans = nums[i];
//             freq = 1;
//         }
//     }



//     return 0;
// }



// most optimized with moor's voting algorithm

    int main(){


        vector<int>nums = {2,2,1,1,1,2,2};

        int ans = 0;
        int freq = 0;

        for(int i=0; i<nums.size(); i++){

            if(freq == 0){
                ans = nums[i];
            }

            if(nums.at(i) == ans){
                freq++;
            } else{
                freq--;
            }
        }


        // extra checking wheather the majority element is there or not;
        int count = 0;
        for(int val : nums){
            if(val == ans){
                count++;
            }
        }

        if(count > nums.size() / 2){
            cout << ans << endl;
        }

        return 0;
    }