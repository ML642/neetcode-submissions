class Solution {
public:

    bool global = false;

    bool dfs(string& s1,string& s2, string& s3,int left,int right,vector<vector<int>>& memo){
        int k = left + right;

        if(k == s3.size()){
            if(left == s1.size() && right == s2.size()){
                memo[left][right] = 1;
                return true;
            }
            else{
                memo[left][right] = -1;
                return false;
            }
        }

        if(memo[left][right] != 0){
            if(memo[left][right] == 1){
                return true;
            }
            else{
                return false;
            }
        }

        if(left<s1.size() && s1[left] == s3[k]){
            if(dfs(s1,s2,s3,left+1,right,memo)){
                memo[left+1][right] = 1;
                return true;
            }
        }

        if(right< s2.size() && s2[right] == s3[k]){
            if(dfs(s1,s2,s3,left,right+1,memo)){
                memo[left][right+1] = 1;
                return true;
            }
        }
        
        memo[left][right] = -1;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        vector<vector<int>> memo(s1.size()+1,vector<int>(s2.size()+1,0));
        return dfs(s1,s2,s3,0,0,memo);
        
    }
};
