#include<iostream>
#include<stack>
using namespace std;

class StImp{
    
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        if (op == '^') return 3;  // exponentiation, right-associative
        return 0;  // for '(' or invalid input
    }

    string IntoPost(string s){
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
                // take out everything from stack and add to ans untill see a '('
                while(!st.empty() && st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                // atlast pop out the opening bracket
                st.pop();
                
            }

            else{
                // it is a operator exceptt '('
                while(!st.empty() && st.top() != '(' &&
                    (precedence(s[i]) < precedence(st.top()) ||
                    (precedence(s[i]) == precedence(st.top()) && s[i] != '^')))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        } 

        // now add remaining operators to the ans
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};

int main(){
    StImp s;

    string expr = "h^m^q^(7-4)";
    
    cout << s.IntoPost(expr) << endl;

}