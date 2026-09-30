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
        if(sum%2==1)return false;
        this->sum_all = sum;
        backtrack(nums,0,0);
        return this->answer;
    }
};
