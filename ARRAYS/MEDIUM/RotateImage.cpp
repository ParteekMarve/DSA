#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // Function to rotate the matrix 90 degrees clockwise using extra space
    vector<vector<int>> rotateClockwise(vector<vector<int>>& matrix) {
        // Get the size of the square matrix
        int n = matrix.size();
        //! OPTIMAL
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                 swap(matrix[i][j],matrix[j][i]);
            }
        }

        //? just reverse the rows the get answer
        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return matrix;
            //! BRUTE
            // Create a new matrix of same size to store rotated result
        //vector<vector<int>> rotated(n, vector<int>(n));
        // Traverse each element of original matrix
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //          Place the element at its new rotated position
        //         rotated[j][n - i - 1] = matrix[i][j];
        //     }
        // }
        // Return the rotated matrix
        // return rotated;
    }
};
int main() {
    vector<vector<int>> orgmat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    vector<vector<int>> rotated =  obj.rotateClockwise(orgmat);

    for(auto row: rotated){   /// learned a new thing how to print elmnts  
        for(int val: row) cout<< val << " ";
        cout<<endl;
    }

    return 0;
}