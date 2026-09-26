class Solution {
public:
    


    int coinChange(vector<int>& coins, int amount) {
        vector<int> a(amount+1,0);
        if(amount==0)return 0;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount)a[coins[i]]=1;
        }
        for(int i=0;i<=amount;i++ )
        {
            if(a[i]!=0){
                    for(int j=0;j<coins.size();j++){
                    long long next = (long long)i + coins[j];

                    if(next<= amount){ 
            
                        if(a[next]!=0){
                            a[next]=min(a[i]+1,a[next]);
                        }
                        else{
                             a[next]=a[i]+1;
                        }
                    }
                }
            }
        }
        if(a[amount]==0)return -1;
        return a[amount];
    }
};
