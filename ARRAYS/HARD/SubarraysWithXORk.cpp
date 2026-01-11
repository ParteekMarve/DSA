#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int count = 0;
        int xorval = 0;
        //! Optimal Solution
        unordered_map<int,int> preXormap;
        preXormap[0] = 0; // we have 0 as prexor value with frequency 1
        for(int i = 0;i<n;i++){
            xorval^= arr[i];
            if(xorval == k) count++;
            int preXorval = xorval^k;
            if(preXormap.find(preXorval) != preXormap.end()){
                 count+= preXormap[preXorval];
            }
            preXormap[xorval]++;
        }

        // Brute Force
        // for(int i = 0;i<n;i++){
        //     int xorval = 0;
        //     for(int j = i;j<n;j++){
        //         int xorval = xorval^arr[j];
        //         if(xorval == k) count++;
        //     }
        // }
       return count;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> arr1 = {4, 2, 2, 6, 4};
    int k1 = 6;
    cout << "Test Case 1:" << endl;
    cout << "Array: [4, 2, 2, 6, 4], k = " << k1 << endl;
    cout << "Number of subarrays with XOR = " << k1 << ": " << solution.subarrayXor(arr1, k1) << endl;
    cout << "Expected: 4" << endl;
    cout << "Subarrays: [4,2], [4,2,2,6,4], [2,2,6], [6]" << endl;
    cout << "\n";
    return 0;
}