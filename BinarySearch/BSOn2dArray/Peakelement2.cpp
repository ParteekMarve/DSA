#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int left_colm = 0 ;
        int right_colm = m-1;
        while(left_colm<=right_colm){
            int mid_colm = left_colm+(right_colm-left_colm)/2;
            int max_row = 0;
            for (int i = 0;i<n;i++){
                if(mat[i][mid_colm] > mat[max_row][mid_colm]){
                    max_row = i;
                }
            }
            int curr_ele = mat[max_row][mid_colm];
            int left_nbr = (mid_colm == 0) ? -1 : mat[max_row][mid_colm-1];
            int right_nbr = (mid_colm == m-1) ? -1 : mat[max_row][mid_colm+1];
            if(curr_ele > left_nbr && curr_ele > right_nbr){
                return {max_row,mid_colm};
            }
            else if( curr_ele < right_nbr){
                left_colm = mid_colm + 1;
            }
            else {
                right_colm = mid_colm-1;
            }
        }
        return {-1,-1};
    }
};

void printMatrix(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        for (int x : row) cout << x << "\t";
        cout << endl;
    }
}

int main() {
    Solution sol;

    // Test 1
    vector<vector<int>> mat1 = {
        {1, 4, 3},
        {2, 9, 5},
        {7, 8, 6}
    };
    cout << "Matrix 1:" << endl;
    printMatrix(mat1);
    vector<int> res1 = sol.findPeakGrid(mat1);
    cout << "Peak at: [" << res1[0] << ", " << res1[1] << "] "
         << "=> Value: " << mat1[res1[0]][res1[1]] << endl;

    cout << endl;

    // Test 2
    vector<vector<int>> mat2 = {
        {10, 20, 15},
        {21, 30, 14},
        {7,  16, 32}
    };
    cout << "Matrix 2:" << endl;
    printMatrix(mat2);
    vector<int> res2 = sol.findPeakGrid(mat2);
    cout << "Peak at: [" << res2[0] << ", " << res2[1] << "] "
         << "=> Value: " << mat2[res2[0]][res2[1]] << endl;

    cout << endl;

    // Test 3: Single element
    vector<vector<int>> mat3 = {{42}};
    cout << "Matrix 3 (single element):" << endl;
    printMatrix(mat3);
    vector<int> res3 = sol.findPeakGrid(mat3);
    cout << "Peak at: [" << res3[0] << ", " << res3[1] << "] "
         << "=> Value: " << mat3[res3[0]][res3[1]] << endl;

    return 0;
}