#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int rep_num = -1;
        int miss_num = -1;
        vector<int> result(2);
        // int count = 0;
        int hash[n+1] = {0}; // hashmap
        for(int i = 0;i<n;i++){
           hash[nums[i]]++;
        }
        for(int i = 1;i<=n;i++){
            if(hash[i] == 2) rep_num = i;
            else if(hash[i] == 0) miss_num = i;

            /* If both repeating and missing 
            are found, break out of loop*/
            if (rep_num != -1 && miss_num != -1) {
                break;
            }
        }

        
        result = {rep_num,miss_num};
        return result;
    }
};

#include <iostream>
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> result1 = solution.findErrorNums(nums1);
    cout << "Example 1: [" << result1[0] << "," << result1[1] << "]" << endl;
    return 0;
}