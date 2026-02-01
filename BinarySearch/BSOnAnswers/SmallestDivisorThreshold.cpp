#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
 //* checker function - checks wheather the result is possible or not
    bool isPossible(vector<int>& nums, int threshold, int divisor){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i] / divisor);
        }
        return sum <= threshold;
    }
    
    // --OPTIMAL--
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        long long maxx = *max_element(nums.begin(), nums.end());
        long long low = 1;
        long long high = maxx;
        long long ans = maxx;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossible(nums, threshold, mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    int result1 = sol.smallestDivisor(nums1, threshold1);
    cout << "Test Case 1:" << endl;
    cout << "nums = [1, 2, 5, 9], threshold = 6" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 5" << endl << endl;
    return 0;
}