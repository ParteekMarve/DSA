#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string postToPre(string &exp) {

        stack<string> st;

        for (char ch : exp) {

            // Operand
            if (isalnum(ch)) {
                st.push(string(1, ch));
            }

            // Operator
            else {

                // First pop -> Right operand
                string op2 = st.top();
                st.pop();

                // Second pop -> Left operand
                string op1 = st.top();
                st.pop();

                string expr = ch + op1 + op2;

                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {

    Solution s;

    string postfix = "ab+c*";

    cout << s.postToPre(postfix);

    return 0;
}