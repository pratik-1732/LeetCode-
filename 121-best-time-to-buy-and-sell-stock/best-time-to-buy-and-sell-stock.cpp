class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini= prices[0];
        int ans= INT_MIN;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>mini) ans= max(ans, prices[i]-mini);
            else mini= prices[i];
        }

        if(ans!=INT_MIN) return ans;
        else return 0;
    }
};