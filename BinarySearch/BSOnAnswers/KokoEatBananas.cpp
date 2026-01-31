#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // OPTIMAL - {BINARY SEARCH} bcz here we have a possible range of answer and we know answer will be lying between it also the range is sorted
    long long calculate_time(vector<int>& piles, int speed){
        long long time_taken = 0;
        for(auto pile: piles){
            time_taken += (pile + speed - 1) / speed; // taking ceil hour value for each speed testing
        }
        return time_taken;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int max_pile = *max_element(piles.begin(), piles.end()); 
        int right = max_pile;
        int ans = max_pile; // max possible answer to return if no else found
        
        while(left <= right) {
            int mid = left + (right - left) / 2; // here mid plays as speed
            long long time_taken = calculate_time(piles, mid); // calculating 
            
            if(time_taken <= h) { // if condition is satisfied then mark current speed(mid) as current answer 
                ans = mid; // mid can also be the candidate
                // search in left half for more lower speed which can satisfy the condition 
                right = mid - 1;
            }
            else { // means if time_taken > h then need higher speed therefore move to right half
                left = mid + 1;
            }
        }
        return ans;
    }

    // **BRUTE FORCE**
    // long long calculate_eating_time(vector<int> a, int k){
    //     long long time = 0;
    //     for(auto pile: a){
    //         time += (pile + k - 1) / k;
    //     }
    //     return time;
    // }

    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int n = piles.size();
         // to find k = bananas eating per hour means how much bananas should koko eat so that it can eat all bananas
         // we have range of answers of k from 1 to max pile in array means atmax she can eat biggest pile in one hour. 
    //     int max_val = *max_element(piles.begin(), piles.end());
    //     for(int k = 1; k <= max_val; k++){
    //         long long hours = calculate_eating_time(piles, k);
    //         if(hours <= h) return k;
    //     }
    //     return max_val;
    // }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test Case 1:" << endl;
    cout << "Piles: [3, 6, 7, 11], Hours: " << h1 << endl;
    cout << "Minimum eating speed: " << solution.minEatingSpeed(piles1, h1) << endl;
    cout << endl;
    
    // Test case 2
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours: " << h2 << endl;
    cout << "Minimum eating speed: " << solution.minEatingSpeed(piles2, h2) << endl;
    cout << endl;
    
    // Test case 3
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Test Case 3:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours: " << h3 << endl;
    cout << "Minimum eating speed: " << solution.minEatingSpeed(piles3, h3) << endl;
    cout << endl;
    
    return 0;
}
