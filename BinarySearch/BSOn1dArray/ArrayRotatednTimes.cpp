// Main Idea - We Will find the index of the smallest elmnt and that index will represent the number of times the array been rotated
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        // Optimal
        // Main Idea - We Will find the index of the smallest elmnt and that index will represent the number of times the array been rotated
        int low = 0;
        int high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid] > arr[high]){ // this means minimum is in the right
                low = mid+1;    
            }
            else {
                high = mid;
            }
        }
        return low; // Returning the index of the smallest element

        // *Brute*
        // for(int i= 0;i<n;i++){
        //     /*
        // i want to check if at any index a[i+1] < a[i] then till the number of rotations will be that that index +1
        //     for(int j = i+1;j<n;j++){
        //         if(arr[j] < arr[i]) {
        //             return j;
        //         }
        //     }
        // }
        // return 0;

        // *Better*
        
        // for (int i = 0;i<n-1;i++){
        //     if(arr[i+1] < arr[i]){
        //         return i+1;
        //     }
        // }
        // return 0;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Rotated 4 times
    vector<int> arr1 = {5, 1, 2, 3, 4};
    cout << "Array: [5, 1, 2, 3, 4]" << endl;
    cout << "Number of rotations: " << solution.findKRotation(arr1) << endl << endl;
    
}