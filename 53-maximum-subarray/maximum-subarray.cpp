class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, n=nums.size();
        int maxi= nums[0];
        for(int i=0; i<n; i++){
            sum+=nums[i];
            maxi= max(maxi, sum);
            if(sum<0) sum=0;
        }
        // for(int i=si; i<=ei; i++){
        //     cout<<nums[i]<<" ";
        // }
        //cout<<sum<<endl;
        return maxi;
    }
};