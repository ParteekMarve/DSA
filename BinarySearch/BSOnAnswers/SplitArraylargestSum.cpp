#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    // Check if we can split array into <= k subarrays with max sum <= current_sum
    bool isPossible(vector<int>& nums, int k, int current_sum){
        int running_sum = 0;
        int array_halves = 1;  // Start with 1 subarray (we're already in the first one)
        
        for(auto num: nums){
            // Try to add current element to the current subarray
            if(running_sum + num <= current_sum){
                running_sum += num;  // Add to current subarray
            }
            else{
                // Can't fit in current subarray, start a new one
                array_halves++;           // Increment subarray count
                running_sum = num;        // New subarray starts with current element
            }
        }
        
        // Check if we used at most k subarrays
        return array_halves <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Binary search range:
        // Lower bound: max element (every subarray must fit the largest element)
        // Upper bound: sum of all elements (entire array as one subarray)
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        int ans = -1;
        
        // Binary search for the minimum possible "largest sum"
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // If we can split with max sum = mid, try to find smaller max sum
            if(isPossible(nums, k, mid)){
                ans = mid;          // Store current answer
                high = mid - 1;     // Search in left half for smaller value
            }
            else{
                // If we can't split with max sum = mid, we need larger max sum
                low = mid + 1;      // Search in right half
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [7,2,5,10,8], k = 2" << endl;
    cout << "Output: " << sol.splitArray(nums1, k1) << endl;
    cout << "Expected: 18" << endl;
    cout << "Explanation: Split into [7,2,5] (sum=14) and [10,8] (sum=18)" << endl;
    cout << endl;
    return 0;
}