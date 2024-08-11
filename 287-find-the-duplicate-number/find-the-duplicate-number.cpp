class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        vector<int> cnt(n+1, 0);
        int ans;
        for(auto i: nums) {
            if(cnt[i]==0) cnt[i]++;
            else {
                ans= i;
                break;
            }
        }
        return ans;
    }
};