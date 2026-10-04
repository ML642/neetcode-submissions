class Solution {
public:

    int dfs(string& word1, string& word2, int i, int j,vector<vector<int>>& memo){   
        if(i == word1.size()){
            return word2.size()-j;
        }
        if(j == word2.size()){
            return word1.size()-i;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        if(word1[i] == word2[j]){
            return dfs(word1,word2,i+1,j+1,memo);
        }
        
        int insertChar = dfs(word1,word2,i,j+1,memo); 
        
        int deleteChar = dfs(word1,word2,i+1,j,memo);

        int replaceChar = dfs(word1,word2,i+1,j+1,memo);

        memo[i][j] = 1 +  min({
            insertChar,
            deleteChar,
            replaceChar
        });

        return memo[i][j];
    }

  

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(),vector<int>(word2.size(),-1));
        return dfs(word1,word2,0,0,memo);
    }
};
