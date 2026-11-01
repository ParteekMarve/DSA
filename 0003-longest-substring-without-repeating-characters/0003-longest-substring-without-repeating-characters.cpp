class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxlen = INT_MIN;       
        unordered_map<char,int> check;
        int l = 0;
        if(len == 0) return 0;
        for(int r = 0;r<len;r++){
            check[s[r]]++;
            while(check[s[r]] > 1){
                check[s[l]]--;
                l++;
                
            }
            maxlen = max(maxlen,r-l+1);
        }

        return maxlen;
    }
};