class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == nums[i + 1]) return nums[i];
        // }
        
        // return 0;
        
        map<int, int> cnt;
        for(auto i: nums) {
            if(cnt.find(i) != cnt.end()) return i;
            else cnt[i]++;
        }
        return 0;
    }
};