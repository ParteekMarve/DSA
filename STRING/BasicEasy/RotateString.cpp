#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

// OPTIMAL {Hash Array}
bool isAnagram(string s, string t) {
    int l1 = s.length();
    int l2 = t.length();

    if(l1 != l2) return false;

    int freq[26] = {0};

    // increase frequency for s
    for(int i = 0; i < l1; i++){
        freq[s[i] - 'a']++;
    }

    // decrease frequency for t
    for(int i = 0; i < l2; i++){
        freq[t[i] - 'a']--;
    }

    // check if all frequencies are 0
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            return false;
        }
    }

    return true;
}


// BRUTE-1 {HashMap Counting}
bool isAnagram_map(string s, string t) {

    if(s.length() != t.length()) return false;

    unordered_map<char,int> s_count;
    unordered_map<char,int> t_count;

    for(int i = 0; i < s.length(); i++){
        s_count[s[i]]++;
        t_count[t[i]]++;
    }

    for(auto it : s_count){
        if(it.second != t_count[it.first]){
            return false;
        }
    }

    return true;
}


// BRUTE-2 {Sorting}
bool isAnagram_sort(string s, string t) {

    if(s.length() != t.length()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

};

int main(){

    Solution obj;
    string s = "cat";
    string t = "act";

    if(obj.isAnagram(s, t)){
        cout << "Strings are Anagrams\n";
    }
    else{
        cout << "Strings are NOT Anagrams\n";
    }
    return 0;
}