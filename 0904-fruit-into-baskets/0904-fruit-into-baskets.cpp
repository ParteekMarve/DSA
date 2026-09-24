class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        //  ultimaltely what matters is from where u start
        // keep an unorederd set that will contain at max 2 distinct elements at any time
        // whenever it will have more than 2 elements we will delete the leftmost 
        int maxlen = 0;
        int l = 0;
        unordered_map<int,int> mpp;
        for(int r = 0;r<n;r++){ 
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                // keep removing from last
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            
            maxlen = max(maxlen,r-l+1);
        }

        return maxlen;

    }
    // int totalFruit(vector<int>& fruits) {
    //     int n = fruits.size();

    //     //  ultimaltely what matters is from where u start
    //     // keep an unorederd set that will contain at max 2 distinct elements at any time
    //     // whenever it will have more than 2 elements we will delete the leftmost 
    //     int maxlen = 0;
    //     for(int l = 0;l<n;l++){
    //         unordered_map<int,int> mpp;
    //         for(int r = l;r<n;r++){
    //             mpp[fruits[r]]++;
    //             if(mpp.size()>2){
    //                 break;
    //             }
    //             maxlen = max(maxlen,r-l+1);
    //         }
    //     }
    //     return maxlen;

    // }
};