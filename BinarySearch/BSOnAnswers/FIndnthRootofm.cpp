#include <iostream>
#include <cmath>
using namespace std;

class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 0;
        int high = m;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long ans = 1;
            
            // Calculate mid^n
            for(int i = 0; i < n; i++){
                ans *= mid;
                if(ans > m) break;
            }
            
            if(ans == m) return mid;
            else if(ans < m) low = mid + 1;
            else high = mid - 1;
        }
        //! Brute 
        if (m==0) return 0;
    //   for(int i = 1;i<=m;i++){
           // checking i*i*i == m or not   
    //       long long power = pow(i,n);
    //       if(power == m) return i;
    //       if(power > m) break;
    //   }
        return -1;
    }
};

int main() {
    Solution obj;
    
    // Test case 1
    int result1 = obj.nthRoot(3, 27);
    cout << "3rd root of 27 = " << result1 << endl;
    return 0;
}