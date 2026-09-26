class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<int> check;
        int maxlen = 0;
        int left = 0;
        for(int r = 0;r<len;r++){
            int curr = s[r];
            while(check.find(curr) != check.end()){
                check.erase(s[left]);
                left++;
            }
            check.insert(s[r]);
            maxlen = max(maxlen,r-left+1);
        }
        return maxlen;
    }
};