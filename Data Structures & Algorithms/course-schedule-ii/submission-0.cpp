class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);

        vector<int> answer;
        vector<int> indegree(numCourses,0);
        queue<int> q;

        for(auto i : prerequisites){
            edges[i[1]].push_back(i[0]);
        }

        for(auto i:prerequisites){
            indegree[i[0]]++;
        }

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            answer.push_back(top);  
            for(auto i:edges[top]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

        }

        if(answer.size() == numCourses){
            return answer;
        }
        else{
            return {};
        }
    }
};
