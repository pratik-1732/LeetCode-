class Solution {
public:
    // int output(int ind, int flag, vector<int>& prices,  vector<vector<int>> &dp){
    //     if(ind==prices.size()) return 0;
    //     int profit=0;

    //     if(dp[ind][flag] != -1) return dp[ind][flag];
    //     if(flag==1) profit= max(-prices[ind]+output(ind+1, 0, prices, dp), 0+output(ind+1, 1, prices, dp));
    //     else profit= max(prices[ind]+output(ind+1, 1, prices, dp), 0+output(ind+1, 0, prices, dp));

    //     return dp[ind][flag]= profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(2, 0));

        //return output(0, 1, prices, dp);

        // dp[n][0]=0; dp[n][1]=0;

        // for(int i=n-1; i>=0; i--){
        //     for(int f=0; f<=1; f++){
        //         int profit=0;
        //         if(f==1) profit= max(-prices[i]+dp[i+1][0], dp[i+1][1]);
        //         else profit= max(prices[i]+dp[i+1][1], dp[i+1][0]);

        //         dp[i][f]= profit;
        //     }
        // }
        // return dp[0][1];

        vector<int> next(2, 0), curr(2, 0);

        next[0]=0; next[1]=0;

        for(int i=n-1; i>=0; i--){
            for(int f=0; f<=1; f++){
                int profit=0;
                if(f==1) profit= max(-prices[i]+next[0], next[1]);
                else profit= max(prices[i]+next[1], next[0]);

                curr[f]= profit;
            }
            next= curr;
        }
        return next[1];
    }
};