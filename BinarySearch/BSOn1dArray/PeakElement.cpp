#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        // Set left and right bounds
        int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low < high) {
            // Find mid point
            int mid = (low + high) / 2;

            // If mid element is greater than next
            if (nums[mid] > nums[mid + 1]) {
                // Move to left half
                high = mid;
            } else {
                // Move to right half
                low = mid + 1;
            }
        }
        //! Brute Force
        // Cheking 1st elmnt
        // if(n==1 || nums[0] > nums[1]) return 0;
        // Checking the middle elmnts
        // for(int i =1 ;i<n-1;i++){
        //     if(nums[i] > nums[i-1] and nums[i] > nums[i+1]){
        //         return i;
        //     }
        // }
        // Cheking last elmnt
        // if(nums[n-1] > nums[n-2]) return n-1;
        // return -1;

        // Return peak index
        return low;
    }
};

int main() {
    // Input array
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    // Create object
    Solution obj;

    // Output result
    cout << obj.findPeakElement(nums) << endl;

    return 0;
}
