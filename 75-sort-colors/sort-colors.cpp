class Solution {
public:
    int findSmallest(vector<int> nums, int ind){
        int mini= INT_MAX;
        int minInd=-1;
        //cout<<ind<<" ";
        for(int i=ind; i<nums.size(); i++){
            if(mini>nums[i]){
                minInd= i;
                mini=nums[i];
            }
        }
        return minInd;
    }
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int temp= findSmallest(nums, i);
            //cout<<nums[temp]<<endl;
            int t= nums[i]; nums[i]= nums[temp]; nums[temp]= t;
        }
    }
};