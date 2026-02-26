#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    int len = s.length();
    string result = "";
    int i = len - 1;

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        if (i < 0) break;

        int end = i;
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        string new_word = s.substr(i + 1, end - i);

        if (!result.empty()) result += " ";
        result += new_word;
    }

    return result;
}

int main() {
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";

    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << reverseWords(s1) << "\"" << endl;
    cout << endl;

    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << reverseWords(s2) << "\"" << endl;
    cout << endl;

    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << reverseWords(s3) << "\"" << endl;

    return 0;
}