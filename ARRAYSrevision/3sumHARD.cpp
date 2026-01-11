#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniquetriplets;
        vector<vector<int>> ans;
        for(int i =1;i<n;i++){
            // first handling the duplicates
            if(i>0 and nums[i]!= nums[i-1]) continue;
            // 2 pointers for another 2 elements
            int left = i+1;
            int right = n-1;

            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    // Now handling the duplicates for 2nd and 3rd element
                    while(left<right and nums[left] != nums[left-1]) left++;
                    while(left<right and nums[right] != nums[right+1]) right--;
                }
                else if(sum > 0) right--;
                else right++;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    
    cout << "Test Case 1: [-1, 0, 1, 2, -1, -4]" << endl;
    cout << "Triplets that sum to 0:" << endl;
    for(auto triplet : result1) {
        cout << "[";
        for(int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if(i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    cout << "\n";
    return 0;
}
