#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public: 
        vector<int> majorityElementTwo(vector<int>& nums){
            vector<int> result;
            int n = nums.size();
            //! BRUTE FORCE {Checking occurnece for elmnt if its not already added in result vector by keeping a flag }
            for(int i = 0; i < n; i++) {
            // Checking if we have already added this number to result
            bool alreadyInResult = false;
            for(auto it : result) {
                if(it == nums[i]) {
                    alreadyInResult = true;
                    break;
                }
            }
            if(alreadyInResult) continue; // Skip if already added to the result 

            // Count occurrences
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
            if(count > n / 3) {
                result.push_back(nums[i]);
            }

            // Optimization: There can be at most 2 such numbers.
            // If we found them both, we can stop everything.
            if(result.size() == 2) break; 
        }
        
        return result;

        }
   
};

int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11}; 
    //! BETTER {MINIMUM CONDITION}
        // unordered_map<int, int> freq;
        // int minCondition = (n / 3) + 1; // The mInimum Cindition anlemnt
        // should have to enter the resulting array and also doesnot allow
        // duplicate elments to enter for (int i = 0; i < n; i++) {
        //     freq[nums[i]]++;
        //     if (freq[nums[i]] == minCondition) {
        //         result.push_back(nums[i]);
        //     }
        //     if (result.size() == 2)
        //         break;
        // }
        // return result;

        //! OPTIMAL {MOORES VOTING ALGO + MIMIMUM CONDITION}
        // int n;
        // int nums[n];
        // int cnt1 = 0;
        // int cnt2 = 0;
        // //int ele1 = INT_16MIN;
        // //int ele2 = INT_16MIN;
        // for (int i = 0; i < n; i++) {
        //     if (cnt1 == 0 and
        //        // ele2 != nums[i]) { //  must condition for starting = If the
        //                            //  count for 1st elmnt is 0 and also the
        //                            //  current elmnt is 1 we can start counting
        //                            //  for ele1 marking it as the current elmnt
        //         cnt1 = 1;
        //       //  ele1 = nums[i];
        //     } else if (cnt2 == 0 and
        //                ele1 != nums[i]) { //  If the count for 1st elmnt is 0
        //                                   //  and also the current elmnt is 1 we
        //                                   //  can start counting for ele1
        //                                   //  marking it as the current elmnt
        //         cnt2 = 1;
        //         ele2 = nums[i];
        //     } else if (ele1 == nums[i]) {
        //         cnt1++;
        //     } else if (ele2 == nums[i]) {
        //         cnt2++;
        //     } else {
        //         cnt1--;
        //         cnt2--;
        //     }
        // }
        // // STEP 2> TO CONFIRM
        //     //  just reset both the counters to confirm are they n/3

        //     cnt1 = 0, cnt2 = 0;
        //     for (int i = 0; i < n; i++) {
        //         if (nums[i] == ele1){
        //             cnt1++;
        //         }
        //         if (nums[i] == ele2) {
        //             cnt2++;
        //         }
        //     }
        //     int minCondition = (n / 3) + 1;
        //     if (cnt1 >= minCondition)
        //         result.push_back(ele1);
        //     if (cnt2 >= minCondition and ele2 != ele1) { // To avoid Dupliates also
        //         result.push_back(ele2);
        //     }

            //return result;
    // Create an instance of Solution class
    // Solution sol;
    // vector<int> ans = sol.majorityElementTwo(arr);
    // Print the majority elements found
    // cout << "The majority elements are: ";
    // for (auto it : ans) {
    //     cout << it << " ";
    // }
    // cout << "\n";


    return 0;
}
