#include<iostream>
using namespace std;

class Solution {
  public:
    bool isEven(int n) {
        return (n&1) == 0;
    }
};
int main(){
    Solution sol;
    int n;
    cin>> n;
    cout << sol.isEven(n);
}
