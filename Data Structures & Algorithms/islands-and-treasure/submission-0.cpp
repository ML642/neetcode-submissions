class Solution{

public:
	void islandsAndTreasure(vector<vector<int>>& grid){
		queue<vector<int>> q;
		for(int i=0;i<grid.size();i++){
			for(int j=0;j<grid[0].size();j++){
if(grid[i][j]==0)q.push({i,j});
}
}
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

while(!q.empty()){
	int row = q.front()[0];
	int column = q.front()[1];

q.pop();

for(int d=0;d<4;d++){
	int new_row = row + dy[d];
	int new_column = column + dx[d];

	if(new_row >= 0 && new_row<grid.size() && new_column >= 0 && new_column < grid[0].size() && grid[new_row][new_column] == INT_MAX){
	grid[new_row][new_column] = 1 + grid[row][column];
	q.push({new_row,new_column});
}
}
}
	}
	
};

