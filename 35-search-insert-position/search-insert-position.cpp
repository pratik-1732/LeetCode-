class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int ans=INT_MIN, mid;
        if(target<nums[0]) return 0;
        while(l<=r){
            mid= l+(r-l)/2;
            if(nums[mid]==target) return mid;

            else if(nums[mid]<target){
                ans= max(ans, mid);
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans+1;
    }
};