class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m= str1.length(), n=str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                dp[i][j]= 0;
            }
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int same=INT_MIN, nosame=INT_MIN;

                if(str1[i-1]==str2[j-1]) same= 1+dp[i-1][j-1];
                else nosame= 0+max(dp[i-1][j], dp[i][j-1]);

                dp[i][j]= max(same, nosame);
            }
        }
        int i=m, j=n;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+= str1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+= str1[i-1];
                i--;
            }
            else{
                ans+= str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+= str1[i-1];
            i--;
        }
        while(j>0){
            ans+= str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};