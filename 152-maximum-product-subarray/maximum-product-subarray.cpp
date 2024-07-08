// #define long long int
class Solution {
public:
    int output(vector<int> nums, int n){
       long long int ans=nums[0], maxi=nums[0], mini= nums[0];
       for(int i=1; i<n; i++){
            long long int curr= nums[i];
            long long int x= curr*maxi;
            long long int y= curr*mini;
            
            maxi= max(max(x,y),curr);

            mini= min(min(x,y), curr);
            
            if(maxi>=1e10 || maxi<=-1e10) maxi= nums[i];
            if(mini>=1e10 || mini<=-1e10) mini= nums[i];
            ans= max(ans, maxi);
            // if(ans>=1e10 || ans<=-1e10) ans=nums[i];
        }
        return ans;
    // int temp=1;
    // int maxi= INT_MIN;
    // for(int i=0; i<n; i++){
    //     temp*=nums[i];
    //     maxi= max(maxi, temp);
    //     if(temp==0) temp=1;
    // }
    // temp=1;
    // for(int i=n-1; i>=0; i--){
    //     temp*=nums[i];
    //     maxi= max(maxi, temp);
    //     if(temp==0) temp=1;
    // }
    // return maxi;
    }
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        return output(nums, n);
    }
};