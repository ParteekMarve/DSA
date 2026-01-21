#include <bits/stdc++.h>
using namespace std;

// Class to find the lower bound index in an array
class LowerBoundFinder {
public:
    // Function to find the lower bound using binary search
    int lowerBound(vector<int>& nums, int n, int x) {
        //Simple Use in built lower bound function
        return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
        // int lb = n; // retrun the last possible hypothetical index if lb not found 
        // int low = 0;
        // int high = n-1;
        // while(low<=high){
        //     int mid = low+(high-low)/2;
        //     if(nums[mid] >= x){
        //         lb = mid;
        //         high = mid-1;
        //     }
        //     else {
        //         low = mid+1;
        //     }
        // }
        // return lb;
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};  // Sorted input array
    int n = arr.size();                  // Size of array
    int x = 9;                           // Target value

    LowerBoundFinder finder;            // Create object of the class
    int ind = finder.lowerBound(arr, n, x);  // Call method to find lower bound

    cout << "The lower bound is the index: " << ind << "\n";  // Output the result
    return 0;
}
