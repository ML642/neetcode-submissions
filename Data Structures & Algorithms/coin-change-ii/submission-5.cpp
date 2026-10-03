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
        vector<int> dp(amount+1,0);
        dp[0] = 1;

        for(auto coin : coins){
            for(int i = coin;i<=amount;i++){
                dp[i] += dp[i-coin];
            }
        } 
        return dp[amount];
        
    }
};
