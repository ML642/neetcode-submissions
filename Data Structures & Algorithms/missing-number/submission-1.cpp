class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> nummer(nums.size()+1,0);

        for(int i=0;i<nums.size();i++){
            nummer[nums[i]]=1;
        }
        for(int i=0;i<=nums.size();i++){
            if(nummer[i]==0)return i;
        }
        return -1;
    }
};
