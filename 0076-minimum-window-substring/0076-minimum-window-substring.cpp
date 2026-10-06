class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        // get the freq of each character in the stirng 't'

        unordered_map<char,int> tmap;
        for(int i = 0;i<tlen;i++){
            tmap[t[i]]++;
        }
        int min_len = INT_MAX;
        int best_start = 0;
        unordered_map<char,int> curr;

        int l = 0;
        int count = 0;
        for(int r = 0;r<slen;r++){
            curr[s[r]]++;
            // now instead of comparing and rechecking tmap every time 
            // what i can do is whenever i add new charcater to curr map of some window[l...r] 
            // i check whether it is required or not in t string
            // if yes then i have to check whether current occurence is contributing or not
            // if contributing then do something else do nothing

            // check whether useful or not
            if(tmap.find(s[r]) != tmap.end()){
                // present -> reqd
                // now check whether current occurence conrtibuting or not
                if(curr[s[r]] <= tmap[s[r]]){
                    count++;
                }

                while(count == tlen){ // valid window found now try to minimize 
                    if(r-l+1 < min_len){
                        min_len = min(min_len,r-l+1);
                        best_start = l;
                    }

                    // start shrinking from left 
                    curr[s[l]]--;

                    // now check if removal efffects the requirement and then check if it breaks ocuurence
                    if(tmap.find(s[r]) != tmap.end()){ // required character
                        if(curr[s[l]] < tmap[s[l]]){ // breaking occurence
                            count--;
                        }
                    }

                    l++;

                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(best_start,min_len);

    }
// BRUTE FORCE

    // string minWindow(string s, string t) {
    //     int slen = s.length();
    //     int tlen = t.length();
    //     // get the freq of each character in the stirng 't'

    //     unordered_map<char,int> tmap;
    //     for(int i = 0;i<tlen;i++){
    //         tmap[t[i]]++;
    //     }

    //     // now need to get this t in s
    //     int min_len = INT_MAX;
    //     int best_start = 0;
    //     for(int i = 0;i<slen;i++){
    //         unordered_map<char,int> curr;
    //         for(int j = i;j<slen;j++){
    //             curr[s[j]]++;
    //             // now need to check whether 
    //             // therefore loop through the map and compare the values
    //             bool is_valid = true;
    //             for(auto& m : tmap){
    //                 char c = m.first;
    //                 int reqd = m.second;

    //                 if(curr[c] < reqd){
    //                     is_valid = false;
    //                     break; // not valid therefore try next window
    //                 }
    //             }
    //             if(is_valid){
    //                 if(j-i+1<min_len){
    //                     // update min len and best start
    //                     min_len = j-i+1;
    //                     best_start = i;
                        
    //                 }
    //                 break;
    //             }
    //         }
    //     }

    //     return min_len == INT_MAX ? "" : s.substr(best_start,min_len);

    // }
};