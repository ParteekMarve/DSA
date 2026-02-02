#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        // **OPTIMAL**
        // Totally Very Deep observation needed
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int missing_num = arr[mid] - (mid+1);
            if(missing_num<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low+k; 

        // **BRUTE FORCE**
        // int miss_num = 0;// count for how many numbers have i missed | when miss_num ==k return that number
        // for(int i = 0;i<n;i++){
        //     if(arr[i] <= k) k++;
        //     else {
        //         break;
        //     }
        // }
        // return k;
    }

};

int main() {
    Solution sol;
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Test 1: arr = [2,3,4,7,11], k = " << k1 << endl;
    cout << "Result: " << sol.findKthPositive(arr1, k1) << endl;
    cout << "Expected: 9" << endl << endl;
    return 0;
}