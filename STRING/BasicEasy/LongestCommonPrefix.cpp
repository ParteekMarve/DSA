#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int len = strs.size();
        // i have to get return that part which is common in all strings
        string common = "";
        for(int i = 0;i<strs[0].size();i++){
            // compare each character of 1st string with characters of other strings
            char c = strs[0][i];
            for(int j = 1;j<len;j++){
                if( i >= strs[j].size() || strs[j][i] != c){
                    return common;
                }
            }
            common+=c;
        }
        return common;
    }
};

int main(){
    vector<string> strs = {"dog","racecar","car"};
    Solution sol;
    string result = sol.longestCommonPrefix(strs);
    if(result.empty()) {
        cout << " No Common Prefix Found";
    }
    else {
        cout<< result;
    }

}