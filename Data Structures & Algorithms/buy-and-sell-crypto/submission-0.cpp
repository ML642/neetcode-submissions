class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_=99999;
        int answer=0;

        for(int i=0;i<prices.size();i++){
            
            int profit = prices[i]-min_;
            answer=max(answer,profit);
            if(prices[i]<min_){
                min_=prices[i];
            }

        }
        return answer;

    }
};
