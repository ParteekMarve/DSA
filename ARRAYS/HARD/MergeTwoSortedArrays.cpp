#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    void merge(vector<int>& nums1,int m, vector<int>& nums2,int n){
        vector<int> ans;
        //* Optimal{no extra space}
        //! 2 pointer Approach
        //? Main Idea-{as arrays are sorted therefore the largest elmnts will be at end therefore 
        //? if we start comparing elemnts from starting then we will have to continuosly swap the elmnts of 1st array
        //? **Therefore we start compareing elmnts from last of both arrays using 2 pointers an 3rd pointer to keep the track the last position of 1st Array}
        int first_last = m-1; // Last element of nums1 excluding the zeroes 
        int second_last = n-1; //Last element of nums2
        int last_pos = m+n-1;// last position of 1st array
        while(second_last>=0){
            if(nums1[first_last] >= nums2[second_last]){
                nums1[last_pos] = nums1[first_last];
                last_pos--;
                first_last--;
            }
            else{
                nums1[last_pos--] = nums2[second_last--]; 
            }
        }
        // now we got array as num1 = {-5, -2, 4, 5,-3, 1, 8}
        // now we have to sort the array somehow using 2 pointers


        // Brute Force{Used Extra Space}
        // for(int i = 0;i<m;i++){
        //     ans.push_back(nums1[i]);
        // }
        // for(int j = 0;j<n;j++){
        //     ans.push_back(nums2[j]);
        // }
        // sort(ans.begin(), ans.end());
         // copy back elemnts to nums1
        // for(int i = 0;i<ans.size();i++){
        //     nums1[i] = ans[i];
        // }
    }
        
};

int main(){
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};  // m =  size till 7 bcz the last 3 zeroes are same as number of elements in mun2 provided for inplace merging of both arays into 1st aaray
    vector<int> nums2 = {-3, 1, 8};
    int m = 4, n = 3;
    
    cout << "Before merge: ";
    for(int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    
    sol.merge(nums1, m, nums2, n);
    
    cout << "After merge: ";
    for(int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
