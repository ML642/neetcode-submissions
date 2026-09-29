class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> no_overlap;
        int n = intervals.size();
        int i = 0;

        sort(intervals.begin(), intervals.end());
        while(i < n-1 ){
            if(intervals[i][1] < intervals[i+1][0] ){
                no_overlap.push_back(intervals[i]);
                i++;
            }
            else{
                vector<int> myinterval = intervals[i];
                i++;
                while( i<n && intervals[i][0]<=myinterval[1]){
                    myinterval[0] = min(myinterval[0],intervals[i][0]);
                    myinterval[1] = max(myinterval[1],intervals[i][1]);
                    i++;
                }
                no_overlap.push_back(myinterval);
            }
        }
        if(i<n) no_overlap.push_back(intervals[i]);
        return no_overlap;
    }
};
