class Solution {
public:
    // int output(int ind, int buy, int chance, int n, vector<int>& prices, vector<vector<vector<int>>> &dp){
    //     if(ind==n || chance==0) return 0;

    //     if(dp[ind][buy][chance] != -1) return dp[ind][buy][chance];

    //     int price=0;
    //     if(buy==1){
    //         return dp[ind][buy][chance]= max(-prices[ind]+output(ind+1, 0, chance, n, prices, dp), output(ind+1, 1, chance, n, prices, dp));
    //     }
    //     return dp[ind][buy][chance]= max(prices[ind]+output(ind+1, 1, chance-1, n, prices, dp), output(ind+1, 0, chance, n, prices, dp));
    // }

    int f(int ind, int transaction, int n, vector<int>& prices, vector<vector<int>> &dp){
        if(ind==n || transaction==4) return 0;

        if(dp[ind][transaction] != -1) return dp[ind][transaction];

        //buy 0,2
        if(transaction%2==0){
            return dp[ind][transaction]= max(-prices[ind]+f(ind+1, transaction+1, n, prices, dp), f(ind+1, transaction, n, prices, dp));
        }
        //sell 1,2
        return dp[ind][transaction]= max(prices[ind]+f(ind+1, transaction+1, n, prices, dp), f(ind+1, transaction, n, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();

        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
       // return output(0, 1, 2, n, prices, dp);

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<=1; j++){
        //         dp[i][j][0]= 0;
        //     }
        // }
        // for(int i=0; i<=1; i++){
        //     for(int j=0; j<3; j++){
        //         dp[n][i][j]= 0;
        //     }
        // }

        // for(int i=n-1; i>=0; i--){
        //     for(int j=0; j<=1; j++){
        //         for(int k=1; k<=2; k++){
        //             if(j==1){
        //                 dp[i][j][k]= max(-prices[i]+dp[i+1][0][k], dp[i+1][1][k]);
        //             }
        //             else{
        //                 dp[i][j][k]= max(prices[i]+dp[i+1][1][k-1], dp[i+1][0][k]);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][2];

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return f(0, 0, n, prices, dp);
    }
};