class Solution{
	
public:
	int orangesRotting (vector<vector<int>>& grid){
		queue<vector<int>> q;
		
		for(int i=0;i<grid.size();i++){
			for(int j=0;j<grid[0].size();j++){
				if(grid[i][j]==2){
q.push({i,j});
}
}
}
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};
int count = -1;
while(!q.empty()){
	int level = q.size();
	
	for(int i=0;i<level;i++){
	int row = q.front()[0];
	int column = q.front()[1];

	q.pop();

	for(int d = 0;d<4;d++){
	int new_row = row + dx[d];
		int new_column = column + dy[d];

		if( new_row >= 0 && new_row<grid.size() && new_column >= 0 && new_column<grid[0].size() && grid[new_row][new_column] == 1){
	grid[new_row][new_column] = 2;
	q.push({new_row,new_column});
}
}
}
count++;
}

for(int i=0;i<grid.size();i++){
			for(int j=0;j<grid[0].size();j++){
				if(grid[i][j]==1)return -1;

}
}

return max(count,0);

}
};
