class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int> nums,vector<int> ans){
        if(nums.size()==0){
            answer.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){

            vector<int> copy = nums;
            ans.push_back(nums[i]);

            swap(copy[i],copy[copy.size()-1]);
            copy.pop_back();
            dfs(copy,ans);
            
            ans.pop_back();

            
        }
    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans{};
        dfs(nums,ans);
        return this->answer;
    }
};

