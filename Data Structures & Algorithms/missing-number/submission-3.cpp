class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xoR = nums.size();

        for(int i=0;i<nums.size();i++){
            xoR = xoR ^ i;
            xoR = xoR ^ nums[i];
        }
        return xoR;
    }
};
