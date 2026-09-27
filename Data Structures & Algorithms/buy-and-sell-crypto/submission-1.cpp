class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_=INT_MAX;
        int answer=0;

        for(int i=1;i<prices.size();i++){
            answer=max(answer,prices[i]-prices[i-1]);
            prices[i]=min(prices[i],prices[i-1]);

        }
        return answer;

    }
};
