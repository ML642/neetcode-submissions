class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,false));
        dp[0][0] = true;

        int left=0,right=0,k=right+left;


        for(int i = 0;i <= s1.size(); i++){
            for(int j = 0;j <= s2.size(); j++){
                int k = i+j-1;

                if( i>0 && s1[i-1] == s3[k] ){
                    if(dp[i-1][j])dp[i][j]=true;
                }
                if( j>0 && s2[j-1] == s3[k]){
                    if(dp[i][j-1])dp[i][j]=true;
                }
            }
        }   
        return dp[s1.size()][s2.size()];
    }
};
