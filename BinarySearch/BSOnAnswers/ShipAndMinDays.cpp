#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int cap){
        int n = weights.size();
        int total_weight = 0;
        int day_count = 1; // day starts from 1 always
        for(int i = 0; i < n; i++){
            if(total_weight + weights[i] <= cap){ // bcz we have to check we are including next weight does it cross the capacity or not 
                total_weight += weights[i]; // if not then add to total_weight till capacity is reached
            }
            else { // if total_weight > cap means can't load more day therefore increase count for the day;
                day_count++; // for the new weight new day is required
                total_weight = weights[i]; // to start the new day with current weight
            }
        }
        return day_count <= days;
    }

    // ***OPTIMAL****
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int minn = *max_element(weights.begin(), weights.end()); // min capacity the ship can handle 
        int maxx = 0;  // max capacity the ship can handle
        for(int i = 0; i < n; i++){
            maxx += weights[i];
        }
        int low = minn;
        int high = maxx;
        int ans = maxx;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    // ** BRUTE**

    // int shipWithinDays(vector<int>& weights, int days) {
    //     int n = weights.size();
    //     int minn = *max_element(weights.begin(),weights.end()); // min capacity the ship can handle 
    //     int maxx = 0;  // max capacity the ship can handle
    //     for(int i = 0;i<n;i++){
    //         maxx+=weights[i];
    //     }
    //     for(int capacity = minn;capacity<= maxx;capacity++){
    //         if(isPossible(weights,days,capacity)){
    //             return capacity;
    //         }
    //     }
    //     return -1;
    // }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Test Case 1:" << endl;
    cout << "Weights: [1,2,3,4,5,6,7,8,9,10], Days: " << days1 << endl;
    cout << "Minimum capacity: " << sol.shipWithinDays(weights1, days1) << endl;
    cout << endl; 
    return 0;
}