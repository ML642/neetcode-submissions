class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            int max2 = -9999;
            for(int j=i;j>=0;j--){
                               

                if(nums[i]>nums[j]){
                    max2 = max(dp[j] + 1,max2);
                }
                
            }
            if(max2!=-9999)dp[i] = max2;
        }
        int max1=-999;
        for(int i=0;i<dp.size();i++){
            max1 = max(dp[i],max1);
        }
        return max1;
    }

};
