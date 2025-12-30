#include<iostream>
using namespace std;
int main(){
    int n = 5;
    int arr[n] = {1,1,2,3,3};
    //! Optimal
    
    
    //! Better Method
        // unordered_map<long long, int> mpp;
        // for(int i = 0;i<n;i++){
        //     mpp[nums[i]]++;    // putting the key(element) and keeping count on its frequency
        // }
        // for(auto it: mpp){
        //     if(it.second == 1) return it.first;   
        // }
        // return -1;

    //! Brute Force
    // for(int i = 0;i<n;i++){
        //     int count  = 0;
        //     int num = nums[i];
        //     for(int j = 0;j<n;j++){
        //         if(nums[j] == num){
        //             count++;
        //         }
        //     }
        //     if(count == 1) return nums[i];
        // }
        // return -1;
}