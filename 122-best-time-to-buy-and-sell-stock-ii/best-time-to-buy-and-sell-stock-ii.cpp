class Solution {
public:
    int output(int ind, int flag, vector<int>& prices,  vector<vector<int>> &dp){
        if(ind==prices.size()) return 0;
        int profit=0;

        if(dp[ind][flag] != -1) return dp[ind][flag];
        if(flag==1) profit= max(-prices[ind]+output(ind+1, 0, prices, dp), 0+output(ind+1, 1, prices, dp));
        else profit= max(prices[ind]+output(ind+1, 1, prices, dp), 0+output(ind+1, 0, prices, dp));

        return dp[ind][flag]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return output(0, 1, prices, dp);
    }
};