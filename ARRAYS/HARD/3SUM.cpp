#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> unq;
        
        //! BETTER APPROACH {LOOP 2 TIMES AND TRY TO FIND 3RD ELEMENT use hashset}
        for(int i = 0; i < n; i++){
            set<int> hashset; // stores the seen values in current iteration
            for(int j = i + 1; j < n; j++){
                int thirdele = -(nums[i] + nums[j]);
                // if 3rd element already in set then add all 3 elements to vector
                if(hashset.find(thirdele) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], thirdele};
                    sort(temp.begin(), temp.end());
                    unq.insert(temp); 
                }
                // else add current element (nums[j]) to hashset for future lookups
                hashset.insert(nums[j]);
            }
        }
       //! BRUTE {LOOP 3 TIMES TO ADD EACH NUMBER AND CHECK}
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int sum = 0;
        //         for (int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());  // as we need the list in the sorted order
        //                 unq.insert(temp);  // inserting the vector/list into the set
        //             }
        //         }
        //     }
        // }
        // Converting Set into vector as we need to return vector of vectors
        vector<vector<int>> ans(unq.begin(), unq.end());
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
