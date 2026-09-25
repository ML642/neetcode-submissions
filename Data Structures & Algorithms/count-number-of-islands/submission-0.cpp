class Solution {
public:
    void islandDfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int r,int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if(visited[r][c]==1){
            return;
        }

        visited[r][c]=1;

        if(grid[r][c]=='0')return;

        islandDfs(grid,visited,r+1,c);
        
        islandDfs(grid,visited,r,c+1);
        
        islandDfs(grid,visited,r,c-1);
        
        islandDfs(grid,visited,r-1,c);


    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size());
        for(int i=0;i<grid.size();i++){
            visited[i] = vector<int>(grid[i].size(),0);
        }
        int count = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!='0' && visited[i][j]!=1){
                    islandDfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
