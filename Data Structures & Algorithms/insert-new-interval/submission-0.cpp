class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int n = intervals.size();
        int i=0;
        while( i<n && intervals[i][1] < newInterval[0] ){
            answer.push_back(intervals[i]);
            i++;
        }
        vector<int> new_interval = newInterval;

        while( i<n && intervals[i][0] <= new_interval[1]){
            new_interval[0] = min(intervals[i][0],new_interval[0]);
            new_interval[1] = max(intervals[i][1],new_interval[1]);
            i++; 
        }

        answer.push_back( new_interval);

        while( i<n ){
            answer.push_back(intervals[i]);
            i++;
        }

        return answer;
    }
};
