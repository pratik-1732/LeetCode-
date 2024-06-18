class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            int mini=i;
            for(int j=i; j<n; j++){
                if(nums[j]<nums[mini]) mini=j;
            }
            int temp= nums[i];
            nums[i]=nums[mini];
            nums[mini]=temp;
        }
    }
};