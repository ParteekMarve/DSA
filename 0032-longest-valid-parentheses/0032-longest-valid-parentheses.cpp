class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int maxlen = 0;
        int ocnt = 0;
        int ccnt = 0;
        vector<int> st = {-1};
        for(int i = 0;i<len;i++){
            if(s[i] == '('){
                st.push_back(i);
            }
            else{
                st.pop_back();

                // and if the stack becomes empty 
                if(st.empty()){
                    st.push_back(i);
                }
                else{
                    maxlen = max(maxlen,i-st.back());
                }

            }
        }
        return maxlen;
    }

// BRUTE FORCE APPRAOCH
    // int longestValidParentheses(string s) {
    //     // dividing it in 2 probelems
    //     // 1. check which substring is valid
    //     // if valid found then get its length and update if its bigger than the
    //     // current maxlen else search for another one if not found then return 0
    //     int len = s.length();
    //     int maxlen = 0;
    //     if (len == 0)
    //         return 0;

    //     for (int i = 0; i < len; i++) {
    //         stack<char> st;
    //         for (int j = i; j < len; j++) {
    //             if (s[j] == '(') {
    //                 st.push(s[j]);
    //             }

    //             else {
    //                 if (st.empty()) {
    //                     // maxlen = max(maxlen,j-i+1);
    //                     break;
    //                 }
    //                 // maxlen = max(maxlen, j - i + 1);
    //                 char top = st.top();
    //                 st.pop();
    //                 // now what i got it now just update the maxlen?
    //             }
    //             if (st.empty()) {
    //                 // update the maxlen bcz its valid nowk
    //                 maxlen = max(maxlen, j - i + 1);
    //             }
    //         }
    //     }
    //     // if(!st.empty());
    //     return maxlen;
    // }
};