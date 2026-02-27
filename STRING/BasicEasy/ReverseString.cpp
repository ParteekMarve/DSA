#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;
//! BRUTE FORCE 
// my thought is to 1st reverse the whole string and then reverse each word and we will be getting answer
    string reverseWords(string s) {
        int len = s.length();
        string word = "";
        string result = "";
        vector<string> get_word;
        for (int i =0;i<len;i++){
            // we need to ensure that if the string is empty we don't include extra space
            if(s[i] == ' '){
                if(!word.empty()){ // need to push only valid words
                    get_word.push_back(word); //* means we inlt push the word when it actually has something
                    word = ""; // resetting word to empty string
                }
            }
            else { // means we are getting non space character
                word+=s[i]; 
            }
        } 
         // push last word (VERY IMPORTANT)
        if (!word.empty()) {
            get_word.push_back(word);
        }
        // now reversing the words in the vector
        // reverse the vector
        reverse(get_word.begin(), get_word.end());
        // Now the words using single space
        for(int i = 0;i<get_word.size();i++){
            if(i!=0) result+= " ";
            result+=get_word[i];
        }
        return result;
    }
//! OPTIMAL -2
// my thought is to 1st reverse the whole string and then reverse each word and we will be getting answer
    // string reverseWords(string s) {
    //     int len = s.length();
    //     string result = "";
    //     reverse(s.begin(),s.end());
    //     for(int i = 0;i<len;i++){
    //         string new_word = "";
    //         while(i<len and s[i] != ' '){
    //             new_word+= s[i];
    //             i++;
    //         }
    //         reverse(new_word.begin(),new_word.end());
    //         if(new_word.length() > 0){
    //             result+= " " + new_word;
    //         }
    //         // here i have to remove somehow the 0th index of result string to get correct answer

    //     }
    //     return result.substr(1);
    // }

//! OPTIMAL -1
// string reverseWords(string s) {
//     int len = s.length();
//     string result = "";
//     int i = len - 1;

//     while (i >= 0) {
//         while (i >= 0 && s[i] == ' ') {
//             i--;
//         }
//         if (i < 0) break;

//         int end = i;
//         while (i >= 0 && s[i] != ' ') {
//             i--;
//         }
//         string new_word = s.substr(i + 1, end - i);

//         if (!result.empty()) result += " ";
//         result += new_word;
//     }

//     return result;
// }

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