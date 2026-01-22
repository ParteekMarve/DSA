#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // Optimized Approach
        //a.>
        // auto lb = lower_bound(nums.begin(),nums.end(),target);
        // auto ub = upper_bound(nums.begin(),nums.end(),target);
        // checking if lower bound of target exists or not
        // if(lb == nums.end() || *lb != target) return {-1,-1};
        // else {
        //     return {int(lb-nums.begin()),int(ub-nums.begin()-1)};
        // }
        // b.> {without using upper or lower bound}
        int low = 0;
        int high = n-1;
        int first_occ = -1;
        int last_occ = -1;
    // 1stly we just have to check wheather the target exists or not
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                first_occ = mid;
                last_occ = mid;
                break;
            }
            else if(target > nums[mid]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        // but if  target was not foung then we have to return -1,-1
        if(first_occ == -1) return {-1,-1};
        // Now searching in left half for 1st occ
        low = 0;
        high = first_occ-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                first_occ = mid;
                // keep searching in left half
                high = mid-1;
            }
            else if(target > nums[mid]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        // Now searching in right half for last occ
        low = first_occ+1;
        high = n-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                last_occ = mid;
                // keep searching in right half
                low = mid+1;
            }
            else if(target > nums[mid]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return {first_occ,last_occ};
        // Brute Force
        // int first_occ = -1;
        // int last_occ = -1;
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == target) {
        //         if(first_occ == -1) {
        //             first_occ = i;
        //         }
        //         last_occ = i; // keep updating last_occ until we reach the last occurrence of target
        //     }
        // }
        // return {first_occ, last_occ};
    }
};

int main() {
    Solution solution;
    
    // Test Case 
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "Test Case 1: [";
    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if(i < nums1.size() - 1) cout << ", ";
    }
    cout << "], target = " << target1 << endl;
    cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << endl;
}
