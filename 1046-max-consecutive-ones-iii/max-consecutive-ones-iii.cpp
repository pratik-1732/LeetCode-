class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0, ans= INT_MIN;
        int i=0,j=0;
        int n= nums.size();
        while(j<n && i<n){
            if(nums[j]==1){
                cnt++;
                j++;
            }
            else{
                if(k>0){
                    k--;
                    cnt++;
                    j++;
                }
                else{
                    if(nums[i]==0 && k<=0){
                        i++;
                        cnt--;
                        k++;
                    }
                    else{
                        while(i<=j && nums[i]!=0){
                            i++;
                            cnt--;
                        }
                    }
                }
            }
            ans= max(ans, cnt);
        }

        return ans;
    }
};