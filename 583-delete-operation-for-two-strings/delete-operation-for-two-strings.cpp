class Solution {
public:

    // int output(string word1, string word2, int i, int j, vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;

    //     if(dp[i][j]!= -1) return dp[i][j];
    //     int match= INT_MIN, nomatch= INT_MIN;

    //     if(word1[i]==word2[j]){
    //         match= 1+output(word1, word2, i-1, j-1, dp);
    //     }
    //     else{
    //         nomatch= 0+max(output(word1, word2, i-1, j, dp), output(word1, word2, i, j-1, dp));
    //     }
    //     return dp[i][j]= max(match, nomatch);
    // }
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // int temp= output(word1, word2, m-1, n-1, dp);
        // return (m+n)-(2*temp);

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                dp[i][j]= 0;
            }
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int match= INT_MIN, nomatch= INT_MIN;

                if(word1[i-1]==word2[j-1]){
                    match= 1+dp[i-1] [j-1];
                }
                else{
                    nomatch= 0+max(dp[i-1] [j], dp[i] [j-1]);
                }
                dp[i][j]= max(match, nomatch);
            }
        }
        int temp= dp[m][n];
        return (m+n)-(2*temp);
    }
};