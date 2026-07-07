#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
//* INTIUTION -- to get the next greater light pole remove all the light poles from inbetween
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }

        return nge;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2, 4};
    vector<int> result = sol.nextLargerElement(arr);

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}