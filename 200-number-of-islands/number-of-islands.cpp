class Solution {
    private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col]= 1;
        vector<int> rv= {-1, 0, 1, 0};
        vector<int> cv= {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow= row+rv[i], ncol= col+cv[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(grid, vis, nrow, ncol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size(), n= grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};