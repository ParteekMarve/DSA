#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Check if it's possible to distribute books among k students 
    // such that no student gets more than 'pages' pages
    bool isPossible(vector<int> &arr, int k, int pages){
        int n = arr.size();
        int current_sum = 0;      // pages assigned to current student
        int student_count = 0;    // number of students used so far
        
        for(int i=0; i<n; i++){
            // Check if we can give this book to current student
            if(current_sum + arr[i] <= pages){ 
                // Yes, current student can take this book
                current_sum += arr[i];
            }
            else {
                // No, giving this book would exceed the limit
                // So current student is done, move to next student
                student_count++;           // one more student completed
                current_sum = arr[i];      // new student starts with this book
            }
        }
        student_count++;  // count the last student (who never triggered else block)
        
        // If students needed <= k, then this distribution is possible
        return student_count <= k;
    }
    //! OPTIMAL
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Edge case: more students than books (impossible to allocate)
        if(k > n) return -1;
        
        // Define search space:
        // Minimum possible answer = largest book (someone has to read it fully)
        int minn = *max_element(arr.begin(), arr.end());
        
        // Maximum possible answer = sum of all books (one student reads everything)
        int maxx = 0;
        for(int i=0; i<n; i++){
            maxx += arr[i];
        }
        
        // Binary search on the answer range [minn, maxx]
        int low = minn;
        int high = maxx;
        int ans = -1;  // stores the minimum valid answer found so far
        
        while(low <= high) {
            int mid = low + (high - low) / 2;  // current guess for max pages
            
            // Check: can we distribute books such that no student gets > mid pages?
            if(isPossible(arr, k, mid)){
                // Yes! mid works, but let's try to find something even smaller
                ans = mid;          // store this as potential answer
                high = mid - 1;     // search in left half for smaller value
            }
            else {
                // No, mid is too small. We need to allow more pages per student
                low = mid + 1;      // search in right half for larger value
            }
        }
        
        return ans;  // return the minimum value where distribution was possible
    }
    //! BRUTE FORCE
    //int findPages(vector<int> &arr, int k) {
    //     int n = arr.size();
    //     if(k > n) return -1;  // more students than books
    //     int minn = *max_element(arr.begin(),arr.end()); // // min possible answer
    //     int maxx = 0; // max possible answer
    //     for(int i= 0;i<n;i++){
    //         maxx+=arr[i];
    //     }
    //     for(int pages = minn;pages<=maxx;pages++){
    //         if(isPossible(arr,k,pages)){
    //             return pages;
    //         }
    //     }
    //     return -1;
    // } 
};

int main() {
    Solution sol;
    vector<int> arr1 = {12, 34, 67, 90};
    int k1 = 2;
    cout << "Test 1: arr = [12, 34, 67, 90], k = 2" << endl;
    cout << "Output: " << sol.findPages(arr1, k1) << endl;
    cout << "Expected: 113" << endl << endl;
}