class Solution{

public:
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,1,-1};	

	int bfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
	queue<vector<int>> q;
	q.push({i,j});
	int count = 1;
	while(!q.empty()){
int row = q.front()[0];
int column = q.front()[1];
q.pop();

for(int d = 0;d<4;d++){
int new_row = row + dy[d];
int new_column = column + dx[d];

if(new_row>=0 && new_row < grid.size() 
	&& new_column >= 0 && new_column < grid[0].size() &&
visited[new_row][new_column] == false &&	    grid[new_row][new_column] ==  1 )
{	
visited[new_row][new_column] = true;
	q.push({new_row,new_column});
	count++;
}		

}
}
return count;
	
}
	
	int maxAreaOfIsland(vector<vector<int>>&  grid){
	vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(),0));
int answer = 0;

for(int i=0;i<grid.size();i++){
   for(int j=0;j<grid[0].size();j++){
if(!visited[i][j] && grid[i][j] == 1){
	visited[i][j] = true;
answer = max( answer, bfs(grid,visited,i,j) );	
}
   }
}
return answer;	
}
};
