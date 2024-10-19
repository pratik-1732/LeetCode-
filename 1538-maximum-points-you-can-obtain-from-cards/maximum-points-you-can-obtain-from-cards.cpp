class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();

        int ans= INT_MIN;
        int lSum=0, rSum=0;
        int l=k-1, r= n-1;

        for(int i=0; i<k; i++) lSum+= cardPoints[i];
        ans= max(ans, lSum);

        while(l>=0 && r>=0){
            lSum-= cardPoints[l];
            l--;
            rSum+= cardPoints[r];
            ans= max(ans, lSum+rSum);
            r--;
        } 
        return ans;
    }
};