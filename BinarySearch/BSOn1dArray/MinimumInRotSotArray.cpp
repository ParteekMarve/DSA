#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<end){
            int mid = start+ (end-start)/2;
            if(nums[mid] > nums[end]){
                // means the minimum is in the right of array
                //update the end
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return nums[start];
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Rotated array
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Array: [3, 4, 5, 1, 2]" << endl;
    cout << "Minimum: " << solution.findMin(nums1) << endl << endl;
    return 0;
}