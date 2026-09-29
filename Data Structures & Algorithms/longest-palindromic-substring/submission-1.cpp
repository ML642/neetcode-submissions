class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int max_string=0;

        int begin=0;
        int length=0;
        for(int len=1;len<=s.size();len++){
            for(int l=0;l+len-1<s.size();l++){
                int r = l+len-1;
                if(s[l]==s[r] && (r-l<=2 || dp[l+1][r-1])){
                    dp[l][r]=true;
                    if(len > max_string){
                        max_string = len;
                        begin = l;
                        length = len;
                    }
                }
            }
        }

        return s.substr(begin,length);
    }
};
