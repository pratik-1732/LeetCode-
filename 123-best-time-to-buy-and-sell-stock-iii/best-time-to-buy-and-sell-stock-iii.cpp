class Solution {
public:
    int output(int ind, int buy, int chance, int n, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(ind==n || chance==0) return 0;

        if(dp[ind][buy][chance] != -1) return dp[ind][buy][chance];

        int price=0;
        if(buy==1){
            return dp[ind][buy][chance]= max(-prices[ind]+output(ind+1, 0, chance, n, prices, dp), output(ind+1, 1, chance, n, prices, dp));
        }
        return dp[ind][buy][chance]= max(prices[ind]+output(ind+1, 1, chance-1, n, prices, dp), output(ind+1, 0, chance, n, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return output(0, 1, 2, n, prices, dp);
    }
};