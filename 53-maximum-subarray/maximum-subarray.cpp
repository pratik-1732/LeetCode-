class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= INT_MIN;
        int sum=0;
        for(auto it: nums){
            //cout<<it<<" "<<sum<<endl;
            if(sum<0) sum=0;
            sum+=it;
            ans= max(ans, sum);
            
        }
        return ans;
    }
};