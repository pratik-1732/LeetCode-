class Solution {
public:

    // int output(string text1, string text2, int n, int m, string &ans, vector<vector<int>> &dp){
    //     if(n<0 || m<0) return 0;

    //     if(dp[n][m]!= -1) return dp[n][m];

    //     int match=INT_MIN, nomatch=INT_MIN;
    //     if(text1[n]==text2[m]){
    //         //ans+= text1[n];
    //         match= 1+output(text1, text2, n-1, m-1, ans, dp);
    //     }
    //     else{
    //         nomatch= 0+ max(output(text1, text2, n-1, m, ans, dp), output(text1, text2, n, m-1, ans, dp));
    //     }
    //     return dp[n][m]= max(match, nomatch);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length(), m=text2.length();
        //string ans="";
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //return output(text1, text2, n-1, m-1, ans, dp);
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++) dp[i][j]=0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int match=INT_MIN, nomatch=INT_MIN;
                if(text1[i-1]==text2[j-1]){
                    //ans+= text1[n];
                    match= 1+dp[i-1] [j-1];
                }
                else{
                    nomatch= 0+ max(dp[i-1] [j] , dp[i] [j-1]);
                }
                dp[i][j]= max(match, nomatch);
            }
        }
        return dp[n][m];
    }
};