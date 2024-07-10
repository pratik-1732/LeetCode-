class Solution {
public:
    int output(int n, int i, int len, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0 || i>=len) return 1e8;
        if(n==0) return matrix[n][i];

        if(dp[n][i]!= -1) return dp[n][i];

        int ld=1e8, s=1e8, rd=1e8;
        ld= matrix[n][i]+ output(n-1, i-1, len, matrix, dp);
        s= matrix[n][i]+ output(n-1, i, len, matrix, dp); 
        rd= matrix[n][i]+ output(n-1, i+1, len, matrix, dp);

        return min(ld, min(s, rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        // int mini= INT_MAX;
        // for(int i=0; i<n; i++){
        //     mini= min(mini, output(n-1, i, n, matrix, dp));
        // }
        

        // for(int i=0; i<n; i++){
        //     dp[0][i]= matrix[0][i];
        // }

        // for(int i=1; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         int ld=1e8, s=1e8, rd=1e8;
        //         if(j>0) ld= matrix[i][j]+ dp[i-1] [j-1];
        //         s= matrix[i][j]+ dp[i-1] [j]; 
        //         if(j<n-1) rd= matrix[i][j]+ dp[i-1] [j+1];

        //         dp[i][j]= min(ld, min(s, rd));
        //     }
        // }

        // int mini= INT_MAX;
        // for(int i=0; i<n; i++){
        //     mini= min(mini, dp[n-1][i]);
        // }
        // return mini;



        vector<int> prev(n, -1);

        for(int i=0; i<n; i++){
            prev[i]= matrix[0][i];
        }

        for(int i=1; i<n; i++){
            vector<int> curr(n);
            for(int j=0; j<n; j++){
                int ld=1e8, s=1e8, rd=1e8;
                if(j>0) ld= matrix[i][j]+ prev[j-1];
                s= matrix[i][j]+ prev[j]; 
                if(j<n-1) rd= matrix[i][j]+ prev[j+1];

                curr[j]= min(ld, min(s, rd));
            }
            prev=curr;
        }

        int mini= INT_MAX;
        for(int i=0; i<n; i++){
            mini= min(mini, prev[i]);
        }
        return mini;
    }
};