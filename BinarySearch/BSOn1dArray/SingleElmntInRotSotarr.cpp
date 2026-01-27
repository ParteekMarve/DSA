#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //* Brute Force
        
        // for (int i = 0;i<n-1;i+=2){ // bcz need to check for pairs
        //     if(nums[i]!= nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return nums[n-1];// if no break pairs found then last elmnt is single
        
        //*Optimal*

        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) // Always keep mid at even index for getting proper output
                mid--;
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2; // Bcz we wnat to check pairs as mid+1 has already been computed
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Single element in the middle
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Array: [1, 1, 2, 3, 3, 4, 4, 8, 8]" << endl;
    cout << "Single element: " << solution.singleNonDuplicate(nums1) << endl << endl;
    
    return 0;
}
