class Solution {
public:
    
    int  backtrack(int& amount,vector<int>& coins,int count,int start,vector<vector<int>>& memo){
        if(count == amount){
            return 1;
        };
        if(count > amount){
            return 0;
        }
        if(memo[start][count]!=-1){
            return memo[start][count];
        }

        int ways = 0;
        for(int i=start;i<coins.size();i++){
            count += coins[i];
            ways += backtrack(amount,coins,count,i,memo);
            count -= coins[i];
        }

        memo[start][count] = ways;
        return ways;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size()+1,vector<int>(amount+1,-1));
        return backtrack(amount,coins,0,0,memo);
        
    }
};
