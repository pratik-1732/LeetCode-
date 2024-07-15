class Solution {
public:

    // int output(string s, string str, int m, int n, vector<vector<int>> &dp){
    //     if(m<0 || n<0) return 0;
        
    //     if(dp[m][n]!= -1) return dp[m][n];
        
    //     int same=INT_MIN, nosame=INT_MIN;
    //     if(s[m]==str[n]){
    //         same= 1+output(s, str, m-1, n-1, dp);
    //     }
    //     else{
    //         nosame= 0+max(output(s, str, m-1, n, dp), output(s, str, m, n-1, dp));
    //     }
    //     return dp[m][n]= max(same, nosame);
    // }

    int longestPalindromeSubseq(string s) {
        int len= s.length();
        vector<vector<int>> dp(len+1, vector<int>(len+1, -1));

        string temp=s;

        string str="";
        for(int i= len-1; i>=0; i--){
            str+= s[i];
        }
        
        //return output(s, str, len-1, len-1, dp);
        for(int i=0; i<=len; i++){
            for(int j=0; j<=len; j++){
               dp[i][j]=0;
            }
        }
        for(int i=1; i<=len; i++){
            for(int j=1; j<=len; j++){

                int same=INT_MIN, nosame=INT_MIN;
                if(s[i-1]==str[j-1]) same=1+dp[i-1][j-1];
                else nosame= 0+max(dp[i-1][j], dp[i][j-1]);

                dp[i][j]= max(same, nosame);
            }
        }
        return dp[len][len];
    }
};