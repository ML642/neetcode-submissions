class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int>& nums,int start,vector<int> ans){
        answer.push_back(ans);

        for(int i=start;i<nums.size();i++){
            ans.push_back(nums[i]);
            dfs(nums,i+1,ans);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        dfs(nums,0,ans);

        return answer;
    }
};
