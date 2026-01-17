#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ========== BRUTE FORCE APPROACH ==========
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int maxProductBrute(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    
    // Try all possible subarrays
    for(int i = 0; i < n; i++) {
        int product = 1;
        for(int j = i; j < n; j++) {
            product *= nums[j];
            maxi = max(maxi, product);
        }
    }
    
    return maxi;
}

// ========== OPTIMAL APPROACH (Prefix-Suffix) ==========
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProductOptimal(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    
    int prefix_product = 1;
    int suffix_product = 1;
    
    // Prefix pass (left to right)
    for(int i = 0; i < n; i++) {
        if(prefix_product == 0) prefix_product = 1;
        prefix_product *= nums[i];
        maxi = max(prefix_product, maxi);
    }
    
    // Suffix pass (right to left)
    for(int i = n - 1; i >= 0; i--) {
        if(suffix_product == 0) suffix_product = 1;
        suffix_product *= nums[i];
        maxi = max(suffix_product, maxi);
    }
    
    return maxi;
}

// ========== ALTERNATIVE OPTIMAL (Single Pass) ==========
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProductOptimalSinglePass(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    
    int prefix_product = 1;
    int suffix_product = 1;
    
    for(int i = 0; i < n; i++) {
        if(prefix_product == 0) prefix_product = 1;
        
        prefix_product *= nums[i];
        
        maxi = max(maxi, prefix_product);
    }
    // calculating suffix product
    for(int i= n-1;i>=0;i--){
        if(suffix_product == 0) suffix_product = 1;
        suffix_product *= nums[i];
        maxi = max(maxi, suffix_product);
    }
    return maxi;
};

int main() {
    // Test Case 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Test Case 1: [2, 3, -2, 4]" << endl;
    cout << "Brute Force: " << maxProductBrute(nums1) << endl;
    cout << "Optimal (Prefix-Suffix): " << maxProductOptimal(nums1) << endl;
    cout << "Optimal: " << maxProductOptimalSinglePass(nums1) << endl;
    cout << "Expected: 6\n" << endl;
    return 0;
}