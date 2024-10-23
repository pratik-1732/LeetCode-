class Solution {
public:
    int output(vector<int>& nums, int goal){
        int n= nums.size();
        int l=0, r=0;
        int sum=0, ans=0;

        while(r<n){
            sum+= nums[r]%2;
            
            while(sum>goal){
                sum-= nums[l]%2;
                l++;
            }
            ans+= (r-l+1);
            r++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       int equal= output(nums, k);
       int less= output(nums, k-1);

       return equal-less;
    }
};