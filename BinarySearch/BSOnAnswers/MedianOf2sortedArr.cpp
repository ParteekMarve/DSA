#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // OPTIMAL SOLUTION - Binary Search O(log(min(n,m)))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        // Always binary search on the smaller array
        if (m < n)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;  
        int high = n; 
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = ((n + m + 1) / 2) - cut1;

            // Get left elements
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // Get right elements
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Check if valid partition
            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        
        return 0.0; // Should never reach here
    }

    // BETTER SOLUTION - Two Pointers (Partial Merge) O(n+m)
    double findMedianBetter(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        
        int curr = 0; // the middle element
        int prev = 0; // the middle - 1 element (needed if total is even)
        int i = 0;    // pointer for nums1
        int j = 0;    // pointer for nums2
        
        // We need to iterate (total/2 + 1) times to get both middle elements
        for(int count = 0; count <= total/2; count++) {
            prev = curr;  // Save current value as previous

            // Choose smaller element from nums1[i] or nums2[j]
            // Handle boundary cases when one array is exhausted
            if(i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            }
            else {
                curr = nums2[j];
                j++;
            }
        }
        
        if(total % 2 != 0) {  // if total is odd
            return curr;
        }
        else {
            return (curr + prev) / 2.0;
        }
    }

    // BRUTE FORCE SOLUTION - Full Merge O(n+m) + O(n+m) space
    double findMedianBrute(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> merged;
        int i = 0; // pointer for nums1
        int j = 0; // pointer for nums2
        
        // Merge both arrays
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1
        while(i < n) {
            merged.push_back(nums1[i]);
            i++;
        }
        
        // Add remaining elements from nums2
        while(j < m) {
            merged.push_back(nums2[j]);
            j++;
        }
        
        // Calculate median from merged array
        int total = merged.size();
        if(total % 2 != 0) {  // if total is odd
            return merged[total/2];
        }
        else {
            return (merged[(total/2) - 1] + merged[total/2]) / 2.0;
        }
    }
};

int main() {
    Solution sol;

    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    cout << "nums1 = [1, 3]" << endl;
    cout << "nums2 = [2]" << endl;
    cout << "Brute Force Median: " << sol.findMedianBrute(nums1, nums2) << endl;
    cout << "Better Median: " << sol.findMedianBetter(nums1, nums2) << endl;
    cout << "Optimal Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
    cout << "Expected: 2.0" << endl << endl;

    return 0;
}