class Solution {
public:
    vector<vector<int>> answer;
    int length;

    void dfs(vector<int>& nums,vector<int> ans){
        if(nums.empty()){
            answer.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            
            
            vector<int> copy = nums;
            swap(copy[i],copy[copy.size()-1]);
            copy.pop_back();
            dfs(copy,ans);

            ans.pop_back();
        }


    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans{};
        this->length = nums.size();
        dfs(nums,ans);
        return this->answer;
    }
};

