#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string preToPost(string &exp) {

        stack<string> st;

        // Traverse from right to left
        for (int i = exp.size() - 1; i >= 0; i--) {

            // Operand
            if (isalnum(exp[i])) {
                st.push(string(1, exp[i]));
            }

            // Operator
            else {

                // First pop -> Left operand
                string op1 = st.top();
                st.pop();

                // Second pop -> Right operand
                string op2 = st.top();
                st.pop();

                string expr = op1 + op2 + exp[i];

                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {

    Solution s;

    string prefix = "*+abc";

    cout << s.preToPost(prefix);

    return 0;
}