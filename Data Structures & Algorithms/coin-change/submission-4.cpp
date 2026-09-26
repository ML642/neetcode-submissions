class Solution {
public:
    int bfs(vector<int>& coins,int amount,queue<int> amount_queue){
        vector<int> visited(amount+1,0);
        int taken = 1;
        int answer = 999999;
        while(!amount_queue.empty()){    
            int level = amount_queue.size();

            for(int i=0;i<level;i++){
                long long curr = amount_queue.front();
                amount_queue.pop();

                if(amount-curr==0){
                    answer=min(answer,taken);
                }
                if(amount-curr<0){
                    continue;
                }
                for(int i=0;i<coins.size();i++){
                    if(curr+coins[i]<=amount && visited[curr+coins[i]]==0){
                    amount_queue.push(curr+coins[i]);
                    visited[curr+coins[i]]=1;
                    }
                    
                }
            }

            taken++;
            
        }   
        if(answer==999999){
            return -1;
        }else{
            return answer;
        }


    }


    int coinChange(vector<int>& coins, int amount) {
        
        queue<int> change;
        for(int i =0;i<coins.size();i++){
            change.push(coins[i]);
        }
        if(amount == 0) return 0;
        return bfs(coins,amount,change);
    }
};
