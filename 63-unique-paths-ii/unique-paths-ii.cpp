class Solution {
public:
    int output(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(row==0 && col==0) {
            if(obstacleGrid[0][0]!= 1) return 1;
            else return 0;
        }
        if(row<0 || col<0) return 0;

        if(dp[row][col]!= -1) return dp[row][col];

        int up=0, left=0;
        if(row>0){
            if(obstacleGrid[row-1][col]!= 1) up= output(row-1, col, obstacleGrid, dp);
            else up=0;
        }
        if(col>0){
            if(obstacleGrid[row][col-1]!= 1) left= output(row, col-1, obstacleGrid, dp);
            else left=0;
        }
        return dp[row][col]= up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row= obstacleGrid.size();
        int col= obstacleGrid[0].size();
        
        vector<vector<int>> dp(row, vector<int> (col, -1));
        if(obstacleGrid[row-1][col-1]==1) return 0;
       return output(row-1, col-1, obstacleGrid, dp);
    }
};