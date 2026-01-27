#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();  // ✓ ADDED: Define n
        int low = 0;
        int high = n-1;
        int first_occ = -1;
        int last_occ = -1;
        
        // 1stly we just have to check whether the target exists or not
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target){  
                first_occ = mid;
                last_occ = mid;
                break;
            }
            else if(target > arr[mid]){ 
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        // but if target was not found then we have to return 0
        if(first_occ == -1) return 0;  // ✓ FIXED: return {-1,-1}
        
        // Now searching in left half for 1st occ
        low = 0;
        high = first_occ - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target){  
                first_occ = mid;
                // keep searching in left half
                high = mid - 1;
            }
            else if(target > arr[mid]){  
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        // Now searching in right half for last occ
        low = first_occ + 1;
        high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target){  
                last_occ = mid;
                // keep searching in right half
                low = mid + 1;
            }
            else if(target > arr[mid]){  
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return last_occ - first_occ + 1; 
    }
};

int main(){
    Solution soln;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    cout<< "Target: "<< target<<endl;
    cout<<"Frequency: " << soln.countFreq(arr,target);
    
}