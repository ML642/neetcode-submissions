class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> answer;
        priority_queue<pair<int,vector<int>>,
        vector<pair<int,vector<int>>>,
        greater<pair<int,vector<int>>>
        > pointss;
        long long min_dist = 999;
        for(int i=0;i<points.size();i++){
            long long dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            min_dist = min(min_dist,dist);
            pointss.push({dist,points[i]});
        }

        while(!points.empty() && k>0){
            answer.push_back(pointss.top().second);
            pointss.pop();
            k--;
        }

        return answer;

    }
};
