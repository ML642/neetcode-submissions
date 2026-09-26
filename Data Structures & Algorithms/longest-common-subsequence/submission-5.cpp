class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int width = text1.size();
        int length = text2.size();

        vector<vector<int>> dp(length,vector<int>(width,0));
        int ans = 0;

        if(text1[0]==text2[0]){
            dp[0][0]=1;
        }
        for(int i=1;i<length;i++){
            if(dp[i-1][0]==1)dp[i][0]=1;
            if(text2[i] == text1[0])dp[i][0]=1;
        }
        for(int j=1;j<width;j++){
            dp[0][j]=dp[0][j];
            if(dp[0][j-1]==1)dp[0][j]=1;
            if(text1[j] == text2[0])dp[0][j]=1;
        }
        

         
        for(int i=1;i<length;i++){
            for(int j=1;j<width;j++){
                if(text1[j]==text2[i]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                ans = max(ans,dp[i][j]);
            }
                }
        for(int i=0;i<length;i++){
                    for(int j=0;j<width;j++){
                        std::cout<<dp[i][j]<<' ';
                         ans = max(ans,dp[i][j]);
                    }
                    std::cout<<endl;
                   
                }
       
        return ans;
        
    }
};
