class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int count = 0;
        int l = 0;
        unordered_map<char,int> freq;
        for(int r = 0;r<len;r++){
            freq[s[r]]++;

            while(freq['a'] >=1 && freq['b']>=1 && freq['c'] >=1){
                // now got the 1st valid now it will be valid till last index
                // therefore we can directly add n-r into our count
                count+=len-r;
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;
                
            }
            
        }
        return count;
    }
};