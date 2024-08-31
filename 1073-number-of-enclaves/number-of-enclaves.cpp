class Solution {
    private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>> &vis, queue<pair<int, int>> &q){
        vector<int> rv= {-1, 0, 1, 0};
        vector<int> cv= {0, 1, 0, -1};
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow= row+rv[i], ncol= col+cv[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                vis[i][0]=1;
                q.push({i, 0});
            }
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                vis[i][n-1]=1;
                q.push({i, n-1});
            }
        }
        for(int i=0; i<n; i++){
            if(grid[0][i]==1 && !vis[0][i]){
                vis[0][i]=1;
                q.push({0, i});
            }
            if(grid[m-1][i]==1 && !vis[m-1][i]){
                vis[m-1][i]=1;
                q.push({m-1, i});
            }
        }
        bfs(grid, vis, q);
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]= 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};