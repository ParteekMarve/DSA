class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(); 
        int maxlen = 0;

        // in the burte force we are checking each and every subarray also the non valid
        // what we can do is keep a subaaray expading unitll it has <= k 0's in it and when 0's >k the window becomes invalid therefore we shrink untill 
        int left = 0;
        int zero_cnt = 0;
        for(int right = 0;right<n;right++){
            if(nums[right] == 0){
                zero_cnt++;
            }
            while(zero_cnt > k){ 
                if(nums[left] == 0) zero_cnt--;
                left++;
            }
            
            maxlen = max(maxlen,right-left+1);
        }

        return maxlen;
    }
};