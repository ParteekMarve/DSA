#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    int n = s.length();
    string result = "";
    int depth = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth++;
            if (depth > 1) {
                result += s[i];
            }
        } else { // if s[i] == '0' decrease the count
            depth--;
            if (depth > 0) {
                result += s[i];
            }
        }
    }
    return result;
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;
    cout << "Output: " << removeOuterParentheses(s) << endl;
    return 0;
}