class Solution {
public:

    // int solve(int l,int r,vector<int>& cardPoints, int k,int sum){
    //     int temp_k = k;
    //     if(k == 0){
    //         return sum;
    //     }
    //     // choose left
    //     int left = solve(l+1,r,cardPoints,temp_k-1,sum+cardPoints[l]);
    //     //choose right
    //     int right = solve(l,r-1,cardPoints,temp_k-1,sum+cardPoints[r]);

    //     return max(left,right);
    // }


    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxpts = 0;
        // BRUTE FORCE
        // // total 2^k cases i have to generate
        // return maxpts = solve(0,n-1,cardPoints,k,0);        

        //
        int l = 0;
        int r = n-1;
        // get first k
        int sum = 0;
        for(int i = 0;i<k;i++){
            sum+=cardPoints[l];
            l++;
        }
        l--;
        maxpts = max(maxpts,sum);
        

        // start excluding left and adding right
        for(int i = 0;i<k;i++){
            sum-=cardPoints[l]; // remove left part
            sum+=cardPoints[r]; // add right part
            maxpts = max(maxpts,sum);// update at each stage
            l--;
            r--;
        }
        

        return maxpts;
    }
};