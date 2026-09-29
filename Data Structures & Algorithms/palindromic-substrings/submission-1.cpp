class Solution {
public:
    int count(string s,int l,int r){
        int count=0;
        while(l>=0 && r<s.size() && s[r] == s[l]){
            count++;
            r++;
            l--;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count1 = 0;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for(int len=1;len<=s.size();len++){
            for(int l=0;l+len-1<s.size();l++){
                int r = l+len-1;
                if(s[l]==s[r] && (len<=2 || dp[l+1][r-1])){
                    dp[l][r]=true;
                    count1++;
                }
            }
        }
        return count1;
    }
};
