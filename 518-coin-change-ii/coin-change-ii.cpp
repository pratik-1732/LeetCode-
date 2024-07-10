class Solution {
public:
    int output(int n, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(n==0){
            if(amount%coins[n]==0) return 1;
            else return 0;
        }

        if(dp[n][amount]!= -1) return dp[n][amount];

        int take=0;
        if(coins[n]<=amount) take= output(n, coins, amount-coins[n], dp);
        int notake= output(n-1, coins, amount, dp);

        return dp[n][amount]= take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return output(n-1, coins, amount, dp);
    }
};