#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string preToInfix(string &exp) {

        stack<string> st;

        // Traverse from right to left
        for (int i = exp.size() - 1; i >= 0; i--) {

            // Operand
            if (isalnum(exp[i])) {
                st.push(string(1, exp[i]));
            }

            // Operator
            else {

                // First pop -> Left operand - top vala
                string op1 = st.top();
                st.pop();

                // Second pop -> Right operand - 2nd top
                string op2 = st.top();
                st.pop();

                string expr = "(" + op1 + exp[i] + op2 + ")";
                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {

    Solution s;

    string prefix = "*+ab-cd";

    cout << s.preToInfix(prefix);

    return 0;
}