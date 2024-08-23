class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        vector<pair<int, int>> vp;
        for(int i=0; i<nums.size(); i++){
            vp.push_back({nums[i], i});
        }
        sort(vp.begin(), vp.end());
        int l=0, r=nums.size()-1;
        while(l<r){
            if(vp[l].first+vp[r].first==target){
                v.push_back(vp[l].second);
                v.push_back(vp[r].second);
                return v;
            }
            else if(vp[l].first+vp[r].first>target) r--;
            else l++;
        }
        return v;
    }
};