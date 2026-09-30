class Solution {
public:
    bool answer = false;
    int sum_all;
    void backtrack(vector<int>& nums,int start,int sum){
        if(this->answer)return;
        
        if(start == nums.size()){
            if(sum_all/2 == sum) {
                this->answer = true;    
                return;
            }

            return;
        }

        if(sum == sum_all/2){
            this->answer = true;
            return;
        }
        if(sum > sum_all/2){
            return;
        }
        for(int i=start;i<nums.size();i++){
            sum+=nums[i];
            backtrack(nums,i+1,sum);
            sum-=nums[i];
        }
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int target = sum /2;
        if(sum%2==1)return false;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1,false));
        dp[0][0] = true;
        for(int i=1;i<=nums.size();i++){
            
            for(int j=0;j<=target;j++){
                dp[i][j] = dp[i-1][j];

                if(j>=nums[i-1]){
                    dp[i][j] =dp[i][j] ||  dp[i-1][j-nums[i-1]];
                }
                
            }

        }
        return dp[nums.size()][target];
    }
};
