class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int,int> mpp;
        int l = 0;
        int maxlen = 0;
        for(int r = 0;r<n;r++){
            while(mpp.find(s[r]) != mpp.end()){
                mpp.erase(s[l]);
                l++;
            }
            mpp[s[r]]++;
            maxlen = max(maxlen,r-l+1);
        }

        return maxlen;
    }
};