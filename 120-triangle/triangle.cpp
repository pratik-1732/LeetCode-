class Solution {
public:

   int output(int m, int n, int len, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    //len= triangle[m].size();
    if(m==0 && n==0) return triangle[m][n];
    if(m<0) return 1e8;
    if(n<0 || n>=len) return 1e8;

    if(dp[m][n]!= -1) return dp[m][n];
    // cout<<"h"<<endl;

    int left=1e8, right=1e8;
    left= triangle[m][n]+ output(m-1, n-1, len-1, triangle, dp);
    right= triangle[m][n]+ output(m-1, n, len-1, triangle, dp);

    // cout<<m<<", "<<n<<"- "<<left<<", "<<right<<" "<<min(left, right)<<endl;
    return dp[m][n]= min(left, right);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int m= triangle.size();
    int len= triangle[m-1].size();
    
    vector<vector<int>> dp(m, vector<int>(len, -1));
    int mini= INT_MAX;
    for(int i=0; i<len; i++){
        mini= min(mini, output(m-1, i, len, triangle, dp));
    }
    int temp=1;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<temp; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     temp++;
    //     cout<<endl;
    // }
    return mini;
}
};