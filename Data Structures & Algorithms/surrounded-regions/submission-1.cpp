class Solution {
public:

    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& copy){
		int n = board.size();
      int m = board[0].size();


		if(i<0 || i >= n){
			return;
}
if(j<0 || j>=m){
	return;
}


		vector<int> dx = {-1,1,0,0};
	  	vector<int> dy = {0,0,1,-1};
		
		for(int d=0;d<4;d++){
	int new_row = i + dx[d];
	int new_column = j + dy[d];
	if(new_row>=0 && new_row<n && new_column>=0 &&  new_column < m && board[new_row][new_column]=='O' && !copy[new_row][new_column]){
			copy[new_row][new_column] = true;
			dfs(board,new_row,new_column,copy);
}
}		
    }
	
    void solve(vector<vector<char>>& board) {
        int n = board.size();
            int m = board[0].size();

        vector<vector<bool>> copy(n,vector<bool>(m,false));
        queue<vector<int>> q;
	
		


        for(int i=0;i<n;i++){
		if(board[i][m-1] == 'O'){
			copy[i][m-1] = true;
			dfs(board,i,m-1,copy);
}


if(board[i][0] == 'O'){
		
		
		copy[i][0] = true;dfs(board,i,0,copy);
} 
        }
	   for(int j=0;j<m;j++){
if(board[0][j] == 'O'){
	copy[0][j] = true;
	dfs(board,0,j,copy);
}
if(board[n-1][j] == 'O'){
	copy[n-1][j] = true;
	
			dfs(board,n-1,j,copy);
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



