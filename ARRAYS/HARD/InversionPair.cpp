#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int p1 = low;
        int p2 = mid + 1;
        int count = 0;
        
        while(p1 <= mid && p2 <= high){
            if(arr[p1] <= arr[p2]){
                temp.push_back(arr[p1]);
                p1++;
            }
            else {
                temp.push_back(arr[p2]);
                p2++;
                count += (mid - p1 + 1); 
                // matlab isse aage valle elmnts bhi condition ko satisfy karenge 
                // therefore thy all will make inversion pairs therfore count should be added to it
            }
        }
        
        while(p1 <= mid){
            temp.push_back(arr[p1]);
            p1++;
        }
        
        while(p2 <= high){
            temp.push_back(arr[p2]);
            p2++;
        }
        
        // Copy sorted elements back to original array
        for(int i = 0; i < temp.size(); i++){
            arr[low + i] = temp[i];
        }
        
        return count;
    }
    
    int mergeSort(vector<int> &arr, int low, int high){
        if(low >= high) return 0; // Base case
        
        int count = 0;
        int mid = low + (high - low) / 2;  // ✅ Correct mid calculation
        
        count += mergeSort(arr, low, mid);        // counting inversions in left half
        count += mergeSort(arr, mid + 1, high);   // counting inversions in right half
        count += merge(arr, low, mid, high);      // count inversions while merging
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

// Helper function to print array
void printArray(vector<int> &arr, string label) {
    cout << label << ": ";
    for(int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Helper function to manually verify inversions{Brute Force}
int bruteForceInversions(vector<int> arr) {
    int count = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    Solution sol;

    // Test Case 1: Random array
    cout << "Test Case 1: Random Array" << endl;
    vector<int> arr1 = {10, 5, 11, 3, 1};
    printArray(arr1, "Original  ");
    int inv1 = sol.inversionCount(arr1);
    printArray(arr1, "Sorted    ");
    cout << "Inversions: " << inv1 << endl;
    cout << "Verified  : " << bruteForceInversions({10, 5, 11, 3, 1}) << endl;
    cout << endl;

    return 0;
}