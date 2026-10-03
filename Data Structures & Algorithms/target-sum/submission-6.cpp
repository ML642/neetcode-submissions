class Solution {
public:
    int global_sum = 0;

    int backtrack(vector<int>& nums,int target,int current,int start,vector<vector<int>>& memo){
        
        

        if(target == current && start == nums.size()){
            
            return 1;
        }    
        if(start == nums.size()){
            return 0 ;
        }
        if(memo[start][current + global_sum] != -1){
            return memo[start][current+global_sum];
        }

        

        int right = backtrack(nums,target,current+nums[start],start+1,memo);

        int left = backtrack(nums,target,current-nums[start],start+1,memo);

        memo[start][current+global_sum] = right+left;

        return memo[start][current+global_sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int start = 0;
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        this->global_sum = sum;

        vector<vector<int>> memo(nums.size(),vector<int>(2*sum+1,-1));
        return backtrack(nums,target,0,0,memo);

    }
};
