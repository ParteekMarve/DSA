#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day){ // helper function
        int count = 0; // calculates adjacent/continuous flowers
        int bouquets = 0;
        for(auto bloom : bloomDay) {
            if(bloom <= day){
                count++;
                if(count == k){ // made a bouquet
                    bouquets++;
                    count = 0;
                }
            }
            else { // means adjacent flower not bloomed, break the chain
                count = 0;
            }
        }
        return bouquets >= m; // returns true if bouquet made for current waiting days else return false
    }

    // ------OPTIMAL{BINARY SEARCH}------------
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total_flowers = (long long)k * m;
        if(total_flowers > n) return -1;
        
        int first_day = *min_element(bloomDay.begin(), bloomDay.end());
        int last_day = *max_element(bloomDay.begin(), bloomDay.end());
        int low = first_day;
        int high = last_day;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // ------- BRUTE-----------
    // int minDays(vector<int>& bloomDay, int m, int k) {
    //     int n = bloomDay.size();
    //     long long total_flowers = (long long)k * m;
    //     if(total_flowers > n) return -1;
    //     int first_day = *min_element(bloomDay.begin(), bloomDay.end());
    //     int last_day = *max_element(bloomDay.begin(), bloomDay.end());
    //     for(int day = first_day; day <= last_day; day++){
    //         if(isPossible(bloomDay, m, k, day)){
    //             return day;
    //         }
    //     }
    //     return -1;
    // }
};

int main() {
    Solution solution;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    cout << "bloomDay = [1, 10, 3, 10, 2]" << endl;
    cout << "m = " << m1 << ", k = " << k1 << endl;
    cout << "Minimum days: " << solution.minDays(bloomDay1, m1, k1) << endl;
    cout << "Expected: 3" << endl;
    cout << endl;
    return 0;
}