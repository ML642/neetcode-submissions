class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        int answer=0;
        for(int i=1;i<=n;i++){
            int count=0;
            int copy = i;
            if(dp[i>>1]!=-1){
            dp[i] = dp[i>>1] + (i&1);
            }        
        }
        return dp;
    }
};
