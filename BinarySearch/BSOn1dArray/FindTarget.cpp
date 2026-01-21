#include <bits/stdc++.h>
using namespace std;

//! Recursive Method
class Solution1 {  // Changed class name to avoid conflict
public:
    int binarySearch2(vector<int>& nums, int target, int low, int high){
        if(low > high){  // Fixed: should be > not >=
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if(target > nums[mid]) return binarySearch2(nums, target, mid + 1, high);
        else return binarySearch2(nums, target, low, mid - 1);
    }
};

//! Iterative Method
class Solution2 {  // Changed class name to avoid conflict
public:
    // Function to perform Binary Search on sorted array
    int binarySearch1(vector<int>& nums, int target) {
        int n = nums.size(); // size of the array
        int low = 0, high = n - 1;

        // Keep searching until low crosses high
        while (low <= high) {
            int mid = low + (high - low) / 2; // Better: avoids overflow
            if (nums[mid] == target) return mid;       // Target found
            else if (target > nums[mid]) low = mid + 1; // Search in right half
            else high = mid - 1;                        // Search in left half
        }
        return -1; // Target not found
    }
};

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int n = a.size();
    int target = 6; // target element to search

    Solution1 obj1; // Create object for recursive solution
    Solution2 obj2; // Create object for iterative solution
    
    int ind1 = obj1.binarySearch2(a, target, 0, n - 1);
    int ind2 = obj2.binarySearch1(a, target);
    
    cout << "Recursive result: ";
    if (ind1 == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind1 << endl;
    
    cout << "Iterative result: ";
    if (ind2 == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind2 << endl;

    return 0;
}