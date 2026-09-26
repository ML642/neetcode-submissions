class Solution {
public:
    vector<vector<int>> answers;

    void backtrack(vector<int>& nums,int current,int target,vector<int>& temp){
        if(target == 0){
            answers.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=current;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i,target-nums[i],temp);
            temp.pop_back();
        }


    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;

        backtrack(nums,0,target,temp);

        return answers;

    }
};
