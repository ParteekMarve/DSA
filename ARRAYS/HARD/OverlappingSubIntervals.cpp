#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        //! OPTIMAL
        //* Main Idea -> /* {*1. Start with first interval → push to ans
        /*2. Move to next interval
        3. Check if it overlaps with last interval in ans
           - If YES → Merge (update the end)
           - If NO → Add it as new interval to ans
        4. Repeat for all intervals}*/
        ans.push_back(intervals[0]);  // i have to push the 1st interval into ans for main idea to work
        if(intervals.empty()) return {};
        for(int i = 0;i<n;i++){
            // 1st check the overlapping condition
            if(intervals[i][0] <= ans.back()[1]){ // if c<=b
                // yes -> overlapping -> merge(update the end)
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        //! Brute Force
//         /*Main Idea
// For each interval, try to merge it with all subsequent intervals that overlap with it, then add the merged result to the answer.*/
//         for(int i = 0;i<n;i++){
//             int start = intervals[i][0];
//             int end = intervals[i][1];
             // firstly check if the current interval is merged or not 
//             if(!ans.empty() and end <= ans.back()[1]) continue; // skip already part of merged intervals\
             // Try to merge with all subsequent intervals
//             for(int j = i+1;j<n;j++){
//                 if(intervals[j][0] <= end){ //  overlapping condition
                     // update the end => merging of intervlas
//                     end = max(end,intervals[j][1]);
//                 }
//                 else{
//                     break; // no more overlapping 
//                 }
//             }
//             ans.push_back({start,end});
//         }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> intervals1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    cout << "Test Case 1: [[1,3], [2,6], [8,10], [15,18]]" << endl;
    vector<vector<int>> result1 = solution.merge(intervals1);
    cout << "Result: ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n\n";
    return 0;
}