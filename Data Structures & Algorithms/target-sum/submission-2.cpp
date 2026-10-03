class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        if (abs(target) > sum)
        return 0;

        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,0));

        dp[0][sum] = 1;

        for(int i = 1; i<=nums.size();i++){
            for(int j = -sum; j <= sum;j++){
                if( j - nums[i-1] >= -sum ) dp[i][j+sum] += dp[i-1][j-nums[i-1]+sum];
                if( j + nums[i-1] <= sum ) dp[i][j+sum] += dp[i-1][j+nums[i-1]+sum];

            }
        }

        return dp[nums.size()][target+sum];
    }
};
