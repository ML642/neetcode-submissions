class Solution {
public:
    vector<vector<string>> answer_global;
    int n;

    void dfs(vector<string> answer,int row, unordered_set<int>& columns,unordered_set<int>& diag1,unordered_set<int>& diag2) 
    {
        if(row == n){
            answer_global.push_back(answer);
            return;
        }

        for(int i = 0;i<n; i++){
            if(columns.contains(i) ||
               diag1.contains(i - row) ||
               diag2.contains(i + row)
               ){
                continue;
            }

            columns.insert(i);
            diag1.insert(i-row);
            diag2.insert(i+row);
            
            string ans(n,'.');
            ans[i] = 'Q';
            answer.push_back(ans);

            dfs(answer,row+1,columns,diag1,diag2);

            answer.pop_back();

            columns.erase(i);
            diag1.erase(i-row);
            diag2.erase(i+row);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> answer;
        unordered_set<int> columns;
        unordered_set<int> diag1;
        unordered_set<int> diag2;
        this->n = n;

        dfs(answer,0,columns,diag1,diag2);        
        return this->answer_global;
    }
};
