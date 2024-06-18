class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            int j=i;
            while(j>0 && nums[j]<nums[j-1]){
                int temp= nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
                j--;
            }
        }
    }
};