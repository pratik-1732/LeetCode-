class Solution {
public:
vector<int> dp;
    int stairs(int n){
        if(n==0) return 1;
        if(n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];

        dp[n]= stairs(n-1)+ stairs(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        dp.resize(n+2);
        for(int i=0; i<=n; i++) dp[i]=-1;

        return stairs(n);
    }
};