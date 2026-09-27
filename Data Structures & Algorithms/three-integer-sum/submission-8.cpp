class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        for(int first=0;first<nums.size();first++){
            if(first>0 && nums[first] == nums[first-1]){
                continue;
            }
            int left = first+1;
            int right = nums.size()-1;
            int sum = -nums[first];

   
            while(right>left){
                if(nums[left]+nums[right]==sum){
                    answer.push_back({nums[first],nums[left],nums[right]});
                }


                if(nums[left]+nums[right]>sum){
                    right--;
                }
                else{
                    left++;
                }
                
                while(left>first+1 && left<nums.size() && nums[left]==nums[left-1]){
                    left++;
                }
                while(right<nums.size()-1 && right>0 && nums[right]==nums[right+1]){
                    right--;
                }
                if(right<=0 || left>=nums.size())break;
            }
        }
        return answer;
    }
};
