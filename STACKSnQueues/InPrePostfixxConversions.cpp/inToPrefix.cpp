#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class StImp{
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        if (op == '^') return 3;
        return 0;
    }

    string IntoPost(string s){   // used only as a helper for prefix, so always strict 
        int i = 0;
        stack<char> st;
        string ans = "";

        while(i<s.size()){
            if(isalnum(s[i])){
                ans+=s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(s[i]) < precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }

    string inToPre(string s){
        // step 1 reverse the given string
        reverse(s.begin(), s.end());
        // step 2 change (->) and )->(
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                s[i] = ')';
            }
            else if(s[i] == ')'){       
                s[i] = '(';
            }
        }
        // step 3 covert the reversed string to postfix
        string ans = IntoPost(s);
        // step 4 reverse again and return
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    StImp s;
    string expr = "(a-b/c)*(a/k-l)";
    cout << s.inToPre(expr) << endl;
    return 0;
}