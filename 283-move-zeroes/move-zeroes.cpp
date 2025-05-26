class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int cnt=0, n= nums.size();
        vector<int> change;
        for(auto it: nums) {
            if(it==0) cnt++;
            else change.push_back(it);
        }
        if(cnt!=n && cnt!=0){
            int j=0;
            for(int i=0; i<change.size(); i++){
                nums[j]= change[i];
                j++;
            }
            j=n-1;
            while(cnt--){
                nums[j]=0;
                j--;
            }
        }
    }
};