class Solution {
public:
    vector<vector<int>> answers;

    void backtrack(vector<int>& candidates,int current,int target,vector<int>& temp){
        if(target == 0){
            answers.push_back(temp);
            return;
        }
        if(target < 0){
            return;
        }

        

        for(int i=current;i<candidates.size();i++){
            if (i > current && candidates[i] == candidates[i - 1])
        continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, i+1,target-candidates[i],temp);
            temp.pop_back();
            
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        unordered_set<int> used;
                sort(candidates.begin(), candidates.end());

        backtrack(candidates,0,target,temp);

        return this->answers;
    }
};
