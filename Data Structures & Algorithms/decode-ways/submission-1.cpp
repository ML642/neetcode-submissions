class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size()+1,0);
        if(s[0]=='0')return 0;
        dp[0]=1;
        
        dp[1]=1;

        for(int i=2;i<s.size()+1;i++){

            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if(two<=26 && two>=10){
                dp[i] += dp[i-2];
            }
            if(s[i-1]!='0'){
                dp[i] += dp[i-1];
            }
            
        }
        return dp[s.size()];
    }
};
