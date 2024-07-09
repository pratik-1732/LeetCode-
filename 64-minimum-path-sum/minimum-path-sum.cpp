
class Solution {
public:

    // int output(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(row==0 && col==0) return grid[row][col];
    //     if(row<0 || col<0) return 0;

    //     if(dp[row][col]!= -1) return dp[row][col];

    //     int  up=INT_MAX, left=INT_MAX;
    //     if(row>0) up= grid[row][col]+output(row-1, col, grid, dp);
    //     if(col>0) left= grid[row][col]+output(row, col-1, grid, dp);

    //     return dp[row][col]= min(up, left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // return output(m-1, n-1, grid, dp);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j]= grid[i][j];
                
                else{
                    int up=1e8, left=1e8;
                    if(i>0) up= grid[i][j]+dp[i-1][j];
                    if(j>0) left= grid[i][j]+dp[i][j-1];
                    dp[i][j]= min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};