class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<vector<int>> edges(numCourses);

        int count = 0;

        for(auto i : prerequisites){
            indegree[i[0]]++;
        }

        for(auto i : prerequisites){
            edges[i[1]].push_back(i[0]);
        }

        for(int i = 0;i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
         }  

         while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto i:edges[top]){
                    indegree[i]--;
                    if(indegree[i]==0){
                        q.push(i);
                        count++;
                }
            }
        }
         return count == numCourses;

    }
};
