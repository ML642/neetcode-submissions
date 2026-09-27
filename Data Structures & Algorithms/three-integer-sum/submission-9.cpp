class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int right=nums.size()-1;
            int left=i+1;
            while(right>left){
                int sum = nums[right]+nums[left]+nums[i];
                if(sum==0){
                    answer.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(right>=0 && nums[right]==nums[right+1]){
                        right--;
                    }
                    while(left<nums.size() && nums[left]==nums[left-1]){
                        left++;
                    }
                }
                if(sum>0){
                    right--;
                }
                if(sum<0){
                    left++;
                }

            }
        }
        return answer;
    }
};
