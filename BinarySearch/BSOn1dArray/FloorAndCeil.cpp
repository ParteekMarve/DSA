// # NOte -> Ceil = Lower Bound
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int floor = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= x) { // Main change
                floor = arr[mid];
                low = mid + 1;// main change
            } 
            else {
                high = mid - 1;
            }
        }
        
        return floor;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 3, 5, 7, 9};
    
    cout << "Floor of 5: " << obj.findFloor(arr, 5) << endl;   // 5
    cout << "Floor of 6: " << obj.findFloor(arr, 6) << endl;   // 5
    cout << "Floor of 0: " << obj.findFloor(arr, 0) << endl;   // -1
    cout << "Floor of 10: " << obj.findFloor(arr, 10) << endl; // 9
    
    return 0;
}
