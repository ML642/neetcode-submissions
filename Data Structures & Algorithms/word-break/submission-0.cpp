class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;

        for(int i=1;i<=s.size();i++){
            
            for(int j=0;j<wordDict.size();j++){
                int length = wordDict[j].size();

                if(i-length>=0){
                    string sub = s.substr(i-length,length);
                    if(sub==wordDict[j] && dp[i-length]){
                        dp[i]=true;
                    }
                }   
            }

        }
        return dp[s.size()];
    }
};
