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
        set<vector<int>> unq;
        //! OPTIMAL {OPTIMAL}
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        // *OPTIMAL* {2 POINTER}
        for(int i = 0; i < n; i++){
            // checking for duplicate and this only happens when the fixed element is at any index except the 0th bcz for 0th idx we have no need to check
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            // 2 pointers for the other two elements
            int left = i + 1;
            int right = n - 1;
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++; // continue search for the next triplets
                    right--;
                    
                    // Skipping the duplicate for both the 2 elements while the condition is met
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                else if(sum > 0) right--;
                else left++;
            }
        }
        return ans;
        
        // //! BETTER APPROACH {LOOP 2 TIMES AND TRY TO FIND 3RD ELEMENT use hashset}
        // for(int i = 0; i < n; i++){
        //     unordered_set<int> hashset; // stores the seen values in current iteration [more efficient than using set here]
        //     for(int j = i + 1; j < n; j++){
        //         int thirdele = -(nums[i] + nums[j]);
                 // if 3rd element already in set then add all 3 elements to vector
        //         if(hashset.find(thirdele) != hashset.end()){
        //             vector<int> temp = {nums[i], nums[j], thirdele};
        //             sort(temp.begin(), temp.end());
        //             unq.insert(temp); 
        //         }
                 // else add current element (nums[j]) to hashset for future lookups
        //         hashset.insert(nums[j]);
        //     }
        // }
        //! BRUTE {LOOP 3 TIMES TO ADD EACH NUMBER AND CHECK THE CONDITION}
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
        // vector<vector<int>> ans(unq.begin(), unq.end());
        // return ans;
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
