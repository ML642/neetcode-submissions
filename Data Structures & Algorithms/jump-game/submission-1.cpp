class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool answer = false;
        int max_jump = 0;

        if(nums.size()==1){
            return true;
        }

        for(int i=0;i<nums.size();i++){
            max_jump--;
            max_jump = max(max_jump,nums[i]);
            if(max_jump>0 && max_jump + i >= nums.size()-1){
                return true;
            }
            if(max_jump==0){
                return false;
            }
        }
        return false;
    }
};
