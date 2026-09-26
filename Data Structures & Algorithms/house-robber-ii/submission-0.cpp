class Solution {
public:
    int helper(vector<int> nums,int start,int end){
        int prev1 = 0;
        int prev2 = 0;
        int answer=0;
        for(int i=start;i<end;i++){
            answer = max(prev2,prev1+nums[i]);

            prev1 = prev2;
            prev2 = answer;

        }

        return max(prev2,prev1);
    }

    int rob(vector<int>& nums) {    
        int length = nums.size();

        if(length==1)return nums[0];

        return max(
            helper(nums,1,length),
            helper(nums,0,length-1)
        );

    }
};
