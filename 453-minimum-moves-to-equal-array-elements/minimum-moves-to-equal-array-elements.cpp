class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        int mini= INT_MAX;
        for(auto i: nums){
            if(i<=mini) mini=i;
        }
        int ans=0;
        for(auto i: nums){
            ans+=(i-mini);
        }
        return ans;
    }
};