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
        
        // *OPTIMAL* {TWO POINTER} - O(n^3)
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                    else if(sum > target) right--;
                    else left++;
                }
            }
        }
        return ans;

        // *BETTER* {HASHING} - O(n^3)
        // set<vector<int>> unq;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         unordered_set<long long> hashset;
        //         for(int k = j + 1; k < n; k++){
        //             long long forth = (long long)target - ((long long)nums[i] + nums[j] + nums[k]);
        //             if(hashset.find(forth) != hashset.end()){
        //                 vector<int> temp = {(int)forth, nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 unq.insert(temp);
        //             }
        //             hashset.insert(nums[k]);
        //         }
        //     }
        // }
        // return vector<vector<int>>(unq.begin(), unq.end());

        // *BRUTE* {FOUR LOOPS} - O(n^4)
        // set<vector<int>> unq;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         for(int k = j + 1; k < n; k++){
        //             for(int l = k + 1; l < n; l++){
        //                 long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
        //                 if(sum == target){
        //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
        //                     sort(temp.begin(), temp.end());
        //                     unq.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return vector<vector<int>>(unq.begin(), unq.end());
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