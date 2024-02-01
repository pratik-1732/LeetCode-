class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=nums.size()-1; i>=0; i--){
            //cout<<k<<endl;
            if(k<=0) break;

            if(ans>nums[i]){
                ans=nums[i];
                k--;
            }
            else k--;
             
        }
        return ans;
    }
};