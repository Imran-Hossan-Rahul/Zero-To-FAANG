#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int main(){

    vector<int>height = {1,8,6,2,5,4,8,3,7};
    int mArea = INT_MIN;
    int start = 0, end = height.size() - 1;

    while(start < end){

        int currMinHeight = min(height[start], height[end]);
        int currWidth = end - start;
        int currArea = currMinHeight * currWidth;

        cout << "curr: " << currArea << endl;

        mArea = max(currArea, mArea);

        cout << mArea << endl;


        height[start] > height[end] ? end-- : start++;
    }

    cout << mArea << endl;

    return 0;
}