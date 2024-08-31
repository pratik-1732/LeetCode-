class Solution {
    private:
    void dfs(vector<vector<char>>& board, vector<vector<int>> &vis, int row, int col){
        // cout<<row<<" "<<col<<endl;
        vis[row][col]= 1;
        vector<int> rv= {0, -1, 0, 1};
        vector<int> cv= {-1, 0, 1, 0};
        for(int i=0; i<4; i++){
            int nrow= row+rv[i], ncol= col+cv[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(board, vis, nrow, ncol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m= board.size(), n= board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            if(board[0][i]=='O' && vis[0][i]==0) dfs(board, vis, 0, i);
            if(board[m-1][i]=='O' && vis[m-1][i]==0) dfs(board, vis, m-1, i);
        }
        for(int i=0; i<m; i++){
            if(board[i][0]=='O' && vis[i][0]==0) dfs(board, vis, i, 0);
            if(board[i][n-1]=='O' && vis[i][n-1]==0) dfs(board, vis, i, n-1);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // cout<<vis[i][j]<<" ";
                if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
            }
            // cout<<endl;
        }
    }
};