class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(int i = 0;i<n;i++){
            sum+=nums[i];

            int need = sum - goal;
            if(mpp.find(need) != mpp.end()){
                cnt+= mpp[need];
            }
            mpp[sum]++;
        }
        return cnt;
    }
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n = nums.size();
    //     int cnt = 0;
    //     for(int i = 0;i<n;i++){
    //         int sum = 0;
    //         for(int j = i;j<n;j++){
    //             sum+=nums[j];
    //             if(sum == goal){
    //                 cnt++;
    //             }
    //             else if(sum > goal){
    //                 break;
    //             }
    //         }
    //     }
    //     return cnt;
    // }
};