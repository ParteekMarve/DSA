#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // Using Binary Search
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If we found the target, return its index
            if (nums[mid] == target)
                return mid;
            // Check which half is sorted
            // Left half is sorted (from low to mid)
            if (nums[low] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[low] <= target && target <= nums[mid]) {
                    // Target is in the sorted left half, search left
                    high = mid - 1;
                } else {
                    // Target is not in the sorted left half, search right
                    low = mid + 1; // means move to the right part of nums bcz not present in left part
                }
            }
            // Right half is sorted (from mid to high)
            else {  
                // Check if target lies within the sorted right half
                if (nums[mid] <= target && target <= nums[high]) {  // yhan par mid as a low kaam kar raha hai for right half ??
                    // Target is in the sorted right half, search right
                    low = mid + 1;
                } else {
                    // Target is not in the sorted right half, search left
                    high = mid - 1;
                }
            }
        }

        // Target not found in the array
        return -1;

        // Brute Force {Simple for loop}
        // for(int i =0;i<n;i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }
        // return -1;
    }
};

int main(){
    Solution sol;
    int target = 0;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << "Target: " << target << endl;
    cout << "Index: " << sol.search(arr, target) << endl;
}