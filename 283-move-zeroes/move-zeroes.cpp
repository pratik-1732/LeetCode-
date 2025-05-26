class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lp=0, rp=0;
        while(rp<nums.size()){
            if(nums[rp]==0) rp++;
            else{
                nums[lp]= nums[rp];
                lp++; rp++;
            }
        }
        while(lp<nums.size()) {
            nums[lp]= 0;
            lp++;
        }
    }
};