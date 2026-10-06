class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();


   vector<vector<bool>> copy(n,vector<bool>(m,false));
        queue<vector<int>> q;


        for(int i=0;i<n;i++){
		if(board[i][m-1] == 'O'){
q.push({i,m-1});
	copy[i][m-1] = true;
}


if(board[i][0] == 'O'){
		q.push({i,0});
		copy[i][0] = true;
} 
        }
	   for(int j=0;j<m;j++){
if(board[0][j] =='O'){
	copy[0][j] = true;
	q.push({0,j});
}
if(board[n-1][j] == 'O' ){
	copy[n-1][j] = true;
	q.push({n-1,j});
}
    }
	  vector<int> dx = {-1,1,0,0};
	  vector<int> dy = {0,0,1,-1};
	  while(!q.empty()){
    		int row = q.front()[0];
		int column = q.front()[1];
		q.pop();


		for(int d=0;d<4;d++){
			int new_row = row + dx[d];
			int new_column = column + dy[d];


		if(new_row>=0 && new_row<n && new_column>=0 &&  new_column < m && board[new_row][new_column]=='O' && !copy[new_row][new_column]){
			copy[new_row][new_column] = true;
			q.push({new_row,new_column});
}
}
  }
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(!copy[i][j] && board[i][j] == 'O'){
	board[i][j] = 'X';
}	
}
}
};



