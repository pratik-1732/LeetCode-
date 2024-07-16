class Solution {
public:
    int minInsertions(string s) {
        int len= s.length();
        string str="";
        for(int i=len-1; i>=0; i--){
            str+=s[i];
        }

        vector<vector<int>> dp(len+1, vector<int>(len+1, -1));
        for(int i=0; i<=len; i++){
            for(int j=0; j<=len; j++) dp[i][j]=0;
        }

        for(int i=1; i<=len; i++){
            for(int j=1; j<=len; j++){
                int same=INT_MIN, nosame=INT_MIN;

                if(s[i-1]==str[j-1]) same= 1+dp[i-1][j-1];
                else nosame= 0+ max(dp[i-1][j], dp[i][j-1]);

                dp[i][j]= max(same, nosame);
            }
        }
        int temp= dp[len][len];
        
        // if(temp==0) return temp;
        // else return (len-(2*temp)+1);
        return len-temp;
    }
};