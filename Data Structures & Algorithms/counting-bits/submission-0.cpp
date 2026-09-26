class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts;
        counts.push_back(0);
        
        for(int i=1;i<=n;i++){
            int count=0;
            int copy = i;
            while(copy){
                copy=copy&(copy-1);
                count++;
            }
            counts.push_back(count);
        }
        return counts;
    }
};
