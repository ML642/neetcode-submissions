class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,queue<vector<int>> roten_queue){
        int turn=-1;
        while(!roten_queue.empty()){
            int length = roten_queue.size();

            for(int i=0;i<length;i++){
                auto row = roten_queue.front()[0];
                auto column = roten_queue.front()[1];
                roten_queue.pop();

                visited[row][column] = 1;
                for(int j=0;j<4;j++){
                    int column_ = column + dx[j];
                    int row_ = row + dy[j];

                    if (row_ >= 0 && row_ < grid.size() &&
    column_ >= 0 && column_ < grid[row_].size() &&
    grid[row_][column_] == 1){
                        grid[row_][column_] = 2;
                        roten_queue.push({row_,column_});
                    } 
                }
            }
            turn++;
        }        
        return turn;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> roten_queue;
        vector<vector<int>> visited(grid.size());

        for(int i=0;i<visited.size();i++){
            visited[i] = vector<int>(grid[i].size(),0);
        }

       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2)roten_queue.push({i,j});
        }
       }
       int count = bfs(grid,visited,roten_queue);

       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==1)return -1;
        }
       }
       return max(count,0);


       

    }
};