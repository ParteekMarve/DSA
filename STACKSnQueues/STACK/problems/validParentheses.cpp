#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st;

        for(int i = 0;i<len;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else {
                // if it is a closing bracket
                if(st.empty()) return false;
                
                char top = st.top();
                st.pop();
                if (s[i] == ')' && top != '(') return false;
                if (s[i] == ']' && top != '[') return false;
                if (s[i] == '}' && top != '{') return false; 
            }
        }
        return st.empty();
    }
}; 



int main(){
    string s = "()[{}]";
    Solution sol;
    cout << (sol.isValid(s) ? "true" : "false") << endl;

}

