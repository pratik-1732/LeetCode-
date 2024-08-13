class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> cnt;
        for(auto i: nums) cnt[i]++;
        int ans=0, count=0;
        for(auto i: cnt){
            if(i.second>count){
                count=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};