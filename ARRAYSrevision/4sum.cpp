#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<n;i++){
            if(i>0 and nums[i] == nums[i-1]) continue;
            for(int j =i+1;j<n;j++){
                if(j>0 and nums[j] == nums[j-1]) continue;
                int left = j+1;
                int right = n-1;
                while(left<right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum==0) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        // Checking for Duplictes for 3rd and 4th element
                        while(left<right  and nums[left] == nums[left-1]) continue;
                        while(left<right  and nums[right] == nums[right+1]) continue; 
                    }
                    else if(sum > 0) right--;
                    else left++;
                }
            }
        }
        return ans;

        
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    
    cout << "Input: nums = [1,0,-1,0,-2,2], target = 0" << endl;
    cout << "Output: [";
    for(int i = 0; i < result1.size(); i++){
        cout << "[";
        for(int j = 0; j < result1[i].size(); j++){
            cout << result1[i][j];
            if(j < result1[i].size() - 1) cout << ",";
        }
        cout << "]";
        if(i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;
    
    return 0;
}