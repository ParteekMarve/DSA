#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
// OPTIMAL
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // start from top right corner 
        // if elmnt > target move left 
        // if elmnt < target move down
        int curr_row = 0;
        int curr_colm = m-1;
        while( curr_row <=n-1 and  curr_colm >= 0){
            int curr_num = matrix[curr_row][curr_colm]; // works as mid
            if( curr_num == target) return true;
            else if(curr_num > target){
                curr_colm--;
            }
            else {
                curr_row++;
            } 
        } 
        return false;
    }

// BETTER 
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
         // check only for that row which can contain the target 
    //     for(int i = 0;i<n;i++){
    //         if(target >= matrix[i][0] and target <= matrix[i][m-1]){
                 // row can contain target element
    //             int low = 0;
    //             int high = m-1;
    //             while(low<=high){
    //                 int mid = low+(high-low)/2;
    //                 if(matrix[i][mid] == target){
    //                     return true;
    //                 }
    //                 else if(matrix[i][mid] > target){
    //                     high = mid-1;
    //                 }
    //                 else {
    //                     low = mid+1;
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1,  4,  7,  11},
        {2,  5,  8,  12},
        {3,  6,  9,  16},
        {10, 13, 14, 17}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Search " << target1 << ": " << (sol.searchMatrix(matrix, target1) ? "Found" : "Not Found") << endl;
    cout << "Search " << target2 << ": " << (sol.searchMatrix(matrix, target2) ? "Found" : "Not Found") << endl;

    return 0;
}