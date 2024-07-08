class Solution {
public:
    int output(int row, int col, vector<vector<int>> &dp){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;

        if(dp[row][col]!= -1) return dp[row][col];

        int up= output(row-1, col, dp);
        int left= output(row, col-1, dp);

        return dp[row][col]= up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return output(m-1, n-1, dp);
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(row==0 && col==0) dp[row][col]= 1;
                else{
                    int up=0, left=0;
                    if(row>0) up= dp[row-1][col];
                    if(col>0) left= dp[row][col-1];

                    dp[row][col]= up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};