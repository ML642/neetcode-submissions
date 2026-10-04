class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int right = 0;
        int current = 0;
        int index = 0;

        int sum_gas = 0;
        int sum_cost = 0;

        for(int i=0;i<gas.size();i++){
            sum_gas+=gas[i];
            sum_cost+=cost[i];
        }
        if(sum_gas<sum_cost){
            return -1;
        }


        while(right < cost.size()){
            current = current + gas[right] - cost[right] ;
            if(current<0){
                current = 0;
                right = right+1;
                index = right;
            }
            else{
                right++;
            }
        }
        return index;
    }
};
