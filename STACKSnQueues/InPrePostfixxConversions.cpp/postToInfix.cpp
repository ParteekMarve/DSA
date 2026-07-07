#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string postToInfix(string s) {
        stack<string> st;

        for (char ch : s) {

            // Operand
            if (isalnum(ch)) {
                // push as a string 
                st.push(string(1, ch));
            }

            // Operator
            else {
                // take out top 2 elemnts and add operator between them and wrap it by () and push into stack as string
                string op2 = st.top();
                st.pop();

                string op1 = st.top();
                st.pop();

                string expr = "(" + op1 + ch + op2 + ")";
                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {
    Solution s;

    string postfix = "ab+c*";

    cout << s.postToInfix(postfix);

    return 0;
}