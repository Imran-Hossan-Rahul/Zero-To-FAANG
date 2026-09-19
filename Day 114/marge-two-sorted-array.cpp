    //We can simple solve this problem by next_permutation(A.begin(), A.end()) but it won't be allowed in the interview
 
    #include <iostream>
    #include <vector>
    using namespace std;


    void margeTwoSortedArray(vector<int>& arr, vector<int>& arr2, int n, int m){

        int idx = m+n-1, i = n-1, j = m-1;        

        while(i>=0 && j>=0){
            if(arr[i] >= arr2[j]){
                arr[idx--] = arr[i--];
            } else{
                arr[idx--] = arr2[j--];
            }
        }

        //reverse(A.begin() + pivot + 1, A.end())
        while(j>=0){
            arr[idx--] = arr2[j--];
        }
    }


    int main(){

        vector<int>arr = {1, 2, 3, 0, 0, 0};
        vector<int>arr2 = {2, 5, 6};
        int n = 3;
        int m = arr2.size();
        int N = arr.size();

        margeTwoSortedArray(arr, arr2, n, m);

        for(int i=0; i<N; i++){
            cout << arr[i] << ", ";
        }
        cout << endl;

        return 0;
    }











