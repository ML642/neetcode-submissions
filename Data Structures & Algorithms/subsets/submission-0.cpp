class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int>& nums,int current,vector<int> answer_){
        if(current==nums.size()){
            this->answer.push_back(answer_);
            return;
            }
        

        dfs(nums,current+1,answer_);

        answer_.push_back(nums[current]);

        dfs(nums,current+1,answer_);

        answer_.pop_back();

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> answer__;

        dfs(nums,0,answer__);

        return this->answer;
    }
};
