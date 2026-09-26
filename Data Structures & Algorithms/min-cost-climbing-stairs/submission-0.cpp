class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> stairs(cost.size());
        
        stairs[0] = cost[0];
        stairs[1] = cost[1];

        for(int i=2;i<cost.size();i++){
            stairs[i] = cost[i] + min(stairs[i-1],stairs[i-2]); 
        }

        return min(stairs[cost.size()-1],stairs[cost.size()-2]);
    }
};
