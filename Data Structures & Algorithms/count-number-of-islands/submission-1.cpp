class Solution {
public:
    void islandBfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int r,int c){
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r,c});

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty()){
            auto node = q.front();
            q.pop();


            visited[node.first][node.second] = 1;

            int i = node.first;
            int j = node.second;
            
            for (int k = 0; k < 4; k++) {
                int newR = i + dr[k];
                int newC = j + dc[k];

                if (newR >= 0 && newR < rows &&
                    newC >= 0 && newC < cols &&
                    grid[newR][newC] == '1' &&
                    visited[newR][newC] == 0) {
                    
                    visited[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }


        }


    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size());
        for(int i=0;i<grid.size();i++){
            visited[i] = vector<int>(grid[i].size(),0);
        }
        int count = 0;
        queue<int> q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!='0' && visited[i][j]!=1){
                    islandBfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
