class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int>& nums,int start){
        if(start == nums.size()){
        answer.push_back(nums);
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            dfs(nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
    

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans{};
        dfs(nums,0);
        return this->answer;
    }
};

