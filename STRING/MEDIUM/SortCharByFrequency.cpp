#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int len = s.length();

        unordered_map<char,int> freq;

        // Count frequency of each character
        for(int i = 0; i < len; i++){
            freq[s[i]]++;
        }

        // Convert map to vector of pairs
        vector<pair<char,int>> vec(freq.begin(), freq.end());
//! # NEW TO ME
        // Sort based on frequency (descending)
        sort(vec.begin(), vec.end(), [](pair<char,int>& a, pair<char,int>& b){
            return a.second > b.second;
        });

        string result = "";

        // Build the result string
        for(auto &p : vec){
            result += string(p.second, p.first);
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "tree";

    string result = obj.frequencySort(s);
    cout << "Sorted by frequency: " << result << endl;
    return 0;
}