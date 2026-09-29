class Solution {
public:
// BRUTE FORCE
    int characterReplacement(string s, int k) {
        int len = s.length();
        int max_len = 0;
        
        unordered_map<char,int> freq;
        int l = 0;
        int maxfreq = 0;
        for(int r = 0;r<len;r++){
            freq[s[r]]++;
            maxfreq = max(maxfreq,freq[s[r]]);

            int changes = (r-l+1) - maxfreq;
            if(changes > k){
                freq[s[l]]--;
                l++;
            }

            max_len = max(max_len,r-l+1);

        }

        return max_len;
    }
    // int characterReplacement(string s, int k) {
    //     int len = s.length();
    //     int max_len = 0;
    //     for(int i = 0;i<len;i++){
    //         unordered_map<char,int> freq;
    //         // as the window only moving forward
    //         // also need to maintain the maxfreq
    //         int maxfreq = 0;
    //         for(int j = i;j<len;j++){
    //             // the number of changes to be made in the window will be:
    //             // window size-maxfreq of any character in the current window
    //             freq[s[j]]++;
    //             maxfreq = max(maxfreq,freq[s[j]]);
    //             int changes = (j-i+1) - maxfreq;

    //             if(changes<=k){ // if we have changes left to be made then update the maxlength
    //                 max_len = max(max_len,j-i+1);
    //             }
    //             else break;
    //         }
    //     }

    //     return max_len;
    // }
};