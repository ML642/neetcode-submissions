class Solution {
public:
    bool dfs(int start,string s,vector<string>& wordDict,vector<int>& memo){
        if(start == s.size()){
            memo[start] = 1;
            return true;
        }

        if(memo[start]==1){
            return true;
        }
        if(memo[start]==-1)
            return false;
        
        for(int j=0;j<wordDict.size();j++){
                    int length = wordDict[j].size();

                
                    string sub = s.substr(start,length);
                    if(sub==wordDict[j]){
                        if(dfs(start+length,s,wordDict,memo)){
                            memo[start]=1;
                            return true;
                        };
                    }
                }   
            memo[start] = -1;
            return false;
        }
        


    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size()+1,0);
        return dfs(0,s,wordDict,memo);
    }
};
