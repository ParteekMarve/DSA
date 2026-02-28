#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // ** OPTIMIZED **
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int index = -1;
        int max_one = 0;
        for(int i = 0; i < n; i++){
            if(arr[i][m-1] == 1){
                int low = 0;
                int high = m-1;
                int first_one = m;
                while(low <= high){
                    int mid = low + (high - low) / 2;
                    if(arr[i][mid] == 1){
                        first_one = mid;
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                int total_ones = m - first_one;
                if(total_ones > max_one){
                    max_one = total_ones;
                    index = i;
                }
            }
        }
        return index;
    }
        // ------BRUTE FORCE------------
    // int rowWithMax1s(vector<vector<int>> &arr) {
    //     int n = arr.size();
    //     int m = arr[0].size();
    //     int result = -1;
    //     int count = 0;
    //     for(int i = 0;i<n;i++){
    //         int curr_count = 0;
    //         for(int j = 0;j<m;j++){
    //             if(arr[i][j] == 1){
    //                 curr_count++;
    //             }
    //             if(curr_count > count){
    //                 result = i;
    //                 count = curr_count;
    //             }
                
    //         }
    //     }
    //     return result;
    // }
};

void printMatrix(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "Row " << i << ": ";
        for (int x : arr[i]) cout << x << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;

    // Test 1: Normal case
    vector<vector<int>> arr1 = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 1},   // max 1s
        {0, 0, 0, 0}
    };
    cout << "Matrix 1:" << endl;
    printMatrix(arr1);
    cout << "Row with max 1s: " << sol.rowWithMax1s(arr1) << endl; // Expected: 2

    cout << endl;

    // Test 2: Tie — should return first row with max
    vector<vector<int>> arr2 = {
        {0, 1, 1, 1},   // 3 ones
        {0, 0, 1, 1},
        {0, 1, 1, 1},   // 3 ones (tie, row 0 should win)
        {0, 0, 0, 1}
    };
    cout << "Matrix 2 (tie case):" << endl;
    printMatrix(arr2);
    cout << "Row with max 1s: " << sol.rowWithMax1s(arr2) << endl; // Expected: 0

    cout << endl;

    // Test 3: No 1s at all
    vector<vector<int>> arr3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Matrix 3 (no 1s):" << endl;
    printMatrix(arr3);
    cout << "Row with max 1s: " << sol.rowWithMax1s(arr3) << endl; // Expected: -1

    cout << endl;

    // Test 4: All 1s in last row
    vector<vector<int>> arr4 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1}    // all 1s
    };
    cout << "Matrix 4 (all 1s in last row):" << endl;
    printMatrix(arr4);
    cout << "Row with max 1s: " << sol.rowWithMax1s(arr4) << endl; // Expected: 2

    return 0;
}