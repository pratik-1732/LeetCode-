class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0, ans= INT_MIN;
        int i=0,j=0;
        int n= nums.size();

        while(j<n && i<n){
            if(nums[j]==0) cnt++;
            if(cnt>k){
                if(nums[i]==0) cnt--;
                i++;
            }
            if(cnt<=k) ans= max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};