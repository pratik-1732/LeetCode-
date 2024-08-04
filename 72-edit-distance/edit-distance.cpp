class Solution {
public:
    int output(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(n<0) return m+1;
        if(m<0) return n+1;

        if(dp[n][m]!= -1) return dp[n][m];

        if(s1[n]==s2[m]) return dp[n][m]= output(n-1, m-1, s1, s2, dp);
        
        return dp[n][m]= 1+ min(output(n-1, m-1, s1, s2, dp),min(output(n-1, m, s1, s2, dp),output(n, m-1, s1, s2, dp)));
    }
    int minDistance(string word1, string word2) {
        int n= word1.length(), m= word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return output(n-1, m-1, word1, word2, dp);
    }
};