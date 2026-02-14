#include <iostream>
#include <vector>
using namespace std;

//  APPROACH 1 — BRUTE FORCE   O(n*m) time | O(1) space
bool bruteForce(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

//  APPROACH 2 — BETTER (Binary Search per row)   O(n log m) time | O(1) space
bool betterBinarySearch(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        // Only binary search the row if target lies within its range
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            int low = 0;
            int high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    high = mid - 1;   // search left half
                } else {
                    low = mid + 1;    // search right half
                }
            }
        }
    }
    return false;
}

// ─────────────────────────────────────────────
//  APPROACH 3 — OPTIMAL (Treat 2D as 1D)   O(log(n*m)) time | O(1) space
//
//  Key idea: A sorted m×n matrix can be visualised as a single sorted
//  1D array of length n*m.  For any index `mid` in that virtual array:
//      row  = mid / m
//      col  = mid % m
// ─────────────────────────────────────────────
bool optimalBinarySearch(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low  = 0;
    int high = (n * m) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;   // avoids integer overflow
        int r   = mid / m;                  // map to row
        int c   = mid % m;                  // map to column
        int curr_element = matrix[r][c];
        if (curr_element == target) {
            return true;
        } else if (curr_element > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

// ─────────────────────────────────────────────
//  HELPER — print result for a test case
// ─────────────────────────────────────────────
void runTest(vector<vector<int>> matrix, int target, int testNo) {
    cout << "─────────────────────────────────────\n";
    cout << "Test Case #" << testNo << "  |  target = " << target << "\n";

    // Print matrix
    cout << "Matrix:\n";
    for (auto& row : matrix) {
        cout << "  [ ";
        for (int val : row) cout << val << " ";
        cout << "]\n";
    }

    cout << "\n";
    cout << "  Brute Force      : " << (bruteForce(matrix, target)         ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
    cout << "  Better (BS/row)  : " << (betterBinarySearch(matrix, target)  ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
    cout << "  Optimal (1D BS)  : " << (optimalBinarySearch(matrix, target) ? "FOUND ✓" : "NOT FOUND ✗") << "\n";
}


int main() {
    vector<vector<int>> matrix1 = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    runTest(matrix1, 3, 1);
}