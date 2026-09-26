class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int>& nums,int start,vector<int> ans){
        if(nums.size()==start){
            answer.push_back(ans);
            return;
        }

        dfs(nums,start+1,ans);

        ans.push_back(nums[start]);

        dfs(nums,start+1,ans);

        ans.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        dfs(nums,0,ans);

        return answer;
    }
};
