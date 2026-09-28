class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_weight;

        for(int i=0;i<stones.size();i++){
            max_weight.push(stones[i]);
        }
        while(max_weight.size()!=1){
            int top = max_weight.top();
            max_weight.pop();
            int second = max_weight.top();
            max_weight.pop();

            if(top!=second){
                max_weight.push(abs(top-second));
            }
            if(max_weight.empty())return 0;
        }
        return max_weight.top();

    }
};
