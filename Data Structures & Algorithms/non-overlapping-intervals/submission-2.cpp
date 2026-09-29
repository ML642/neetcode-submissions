class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& first,const vector<int>& second){
            return first[1] < second[1];
        });
        int count = 0;

        int previous_end = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<previous_end){
                count++;
            }
            else{
                previous_end = intervals[i][1];
            }
        }
        return count;
    }
};
