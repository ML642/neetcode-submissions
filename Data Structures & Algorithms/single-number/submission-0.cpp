class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xoR=nums[0];
        for(int i=1;i<nums.size();i++){
            xoR = xoR^nums[i];
        }
        return xoR;
    }
};
