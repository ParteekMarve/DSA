#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This function returns the floor value of the square root of a number
    int mySqrt(int x) {
        // Handle small numbers directly
        if (x < 2) return x;

        // Initialize binary search range
        int left = 1, right = x / 2, ans = 0;

        // Perform binary search
        while (left <= right) {
            // Find middle point
            long long mid = left + (right - left) / 2;

            // Check if mid*mid is less than or equal to x
            if (mid * mid <= x) {
                // Store mid as potential answer
                ans = mid;
                // Move to right half
                left = mid + 1;
            } else {
                // Move to left half
                right = mid - 1;
            }
        }
        //! Brute 
        // Run loop from 1 to n
        for (int i = 1; i <= x; i++) {
            // Check if i*i <= x
            if ((long long)i * i <= x) {
                // Update answer
                ans = i;
            } else {
                // Break when i*i > x
                break;
            }
        }

        // Return final answer
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}
