class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN, stock=prices[0], n=prices.size();
        for(int i=1; i<n; i++){
            if(prices[i]<stock){
                stock=prices[i];
            }
            else{
                maxi= max(maxi, prices[i]-stock);
            }
        }
        if(maxi!=INT_MIN) return maxi;
        else return 0;
    }
};