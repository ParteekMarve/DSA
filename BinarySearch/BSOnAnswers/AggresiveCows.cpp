//! The Goal: Place k cows in stalls such that the minimum distance between any two of them is as large as possible.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//! BRUTE FORCE SOLUTION
class SolutionBruteForce {
  public:
    bool isPossible(vector<int> &stalls, int k, int current_dist){
        int n = stalls.size();
        int last_pos = stalls[0]; // place the 1st cow at 1st index
        int cow_placed = 1;
        
        for(int i = 1; i < n; i++){
            if(stalls[i] - last_pos >= current_dist){
                // if the condition is satisfied then increase the count of cows placed
                cow_placed++;
                last_pos = stalls[i];
            }
        }
        return cow_placed >= k;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int maxx = stalls[n-1] - stalls[0];
        int max_dist = 0;
        
        // Try all possible distances from 1 to maxx
        for(int current_dist = 1; current_dist <= maxx; current_dist++){
            if(isPossible(stalls, k, current_dist)){
                max_dist = current_dist;
            }
            else {
                break; // No point checking larger distances
            }
        }
        return max_dist;
    }
};

//! OPTIMAL SOLUTION (Binary Search)
class SolutionOptimal {
  public:
    bool isPossible(vector<int> &stalls, int k, int current_dist){
        int n = stalls.size();
        int last_pos = stalls[0]; // place the 1st cow at 1st index
        int cow_placed = 1;
        
        for(int i = 1; i < n; i++){
            if(stalls[i] - last_pos >= current_dist){
                // if the condition is satisfied then increase the count of cows placed
                cow_placed++;
                last_pos = stalls[i];
            }
        }
        return cow_placed >= k;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int maxx = stalls[n-1] - stalls[0];
        int max_dist = 0;
        
        // --**OPTIMAL**--
        // Binary search on the answer
        int low = 1;
        int high = maxx;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(isPossible(stalls, k, mid)){
                max_dist = mid;
                low = mid + 1;  // search for larger distance if possible
            }
            else {
                high = mid - 1;  // search for smaller distance
            }
        }
        return max_dist;
    }
};

int main() {
    // Test Case 1
    cout << "========== Test Case 1 ==========" << endl;
    vector<int> stalls1 = {0, 3, 4, 7, 10, 9};
    int k1 = 4;
    
    cout << "Stalls: ";
    for(int x : stalls1) cout << x << " ";
    cout << "\nNumber of cows (k): " << k1 << endl;
    
    SolutionBruteForce bf1;
    cout << "\nBrute Force Result: " << bf1.aggressiveCows(stalls1, k1) << endl;
    
    vector<int> stalls1_copy = {0, 3, 4, 7, 10, 9}; // Make a copy since sort modifies
    SolutionOptimal opt1;
    cout << "Optimal Result: " << opt1.aggressiveCows(stalls1_copy, k1) << endl;
    cout << "Expected: 3\n" << endl;

}    