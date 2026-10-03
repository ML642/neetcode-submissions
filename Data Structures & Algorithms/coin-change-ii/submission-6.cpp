class Solution {
public:
    
    int  backtrack(int& amount,vector<int>& coins,int count,int start,vector<vector<int>>& memo){
        if(count == amount){
            return 1;
        };
        if(count > amount || coins.size()==start){
            return 0;
        }
        if(memo[start][count]!=-1){
            return memo[start][count];
        }

        
        int ways = 0;
        
        ways += backtrack(amount,coins,count,start+1,memo);

        count += coins[start];

        ways += backtrack(amount,coins,count,start,memo);

        count -= coins[start];


        memo[start][count] = ways;
        return ways;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i = 0; i<=coins.size(); i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                dp[i][j] += dp[i-1][j];
                if(j>=coins[i-1]){
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        } 
        return dp[coins.size()][amount];
        
    }
};
