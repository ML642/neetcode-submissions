class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};

    int bfs(vector<vector<int>>& grid,vector<vector<int>> visited,queue<vector<int>> rotten){
        int row_size = grid[0].size();
        int column_size = grid.size();
        int count = -1;

        while(!rotten.empty()){
            int level = rotten.size();

            for(int i=0;i<level;i++){
                auto vec = rotten.front();
                rotten.pop();
                int x = vec[0];
                int y = vec[1];

                for(int j=0;j<4;j++){
                    int x_ = x + dx[j];
                    int y_ = y + dy[j];

                    if(x_<column_size 
                    && y_<row_size 
                    && x_>= 0
                    && y_>=0
                    && grid[x_][y_]==1
                    && visited[x_][y_]==0
                    )
                    {
                        visited[x_][y_]=1;
                        grid[x_][y_]=2;
                        rotten.push({x_,y_});
                    }
                }
                
            }count++;
        }
         return count;
    }

  

    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> roten;
        vector<vector<int>> visited(grid.size());
        for(int i=0;i<grid.size();i++){
            visited[i] = vector<int>(grid[i].size(),0);
        }


        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    roten.push({i,j});
                }
            }
        }
        int time = bfs(grid,visited,roten);

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return max(time,0);
        


    }
};