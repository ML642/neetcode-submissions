class Solution {
public:
    int rob(vector<int>& nums) {
        // vector<int>& cost(nums.size()); 
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        int prev = nums[0];
        int next = nums[1];
        int third = nums[2]+prev;

        int answer;
        for(int i=3;i<nums.size();i++){
            answer = nums[i] + max(prev,next);
            prev = next;
            next = third;
            third = answer;

        }
        return max(next,third);
    }
};
