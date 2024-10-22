class Solution {
public:
    int output(vector<int>& nums, int goal){
        if(goal<0) return 0;

        int n= nums.size();
        int l=0, r=0;
        int sum=0;
        int ans=0;

        while(r<n){
            sum+= nums[r];
            while(sum>goal && l<=r){
                sum-= nums[l];
                l++;
            }
             ans+= (r-l+1);
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int equal= output(nums, goal);
        int less= output(nums, goal-1);

        // for(int i=0; i<n; i++){
        //     sum=0;
        //     for(int j=i; j<n; j++){
        //         sum+= nums[j];
        //         if(sum==goal) ans++;
        //         if(sum>goal) break;
        //     }
        // }

        return equal-less;
    }
};