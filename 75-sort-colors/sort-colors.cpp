class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<n; i++){
            int curr= nums[i];
            int j=i-1;
            while(j>=0 && curr<nums[j]){
                nums[j+1]= nums[j];
                nums[j]=curr;
                j--;
            }
        }
    }
};