class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1; i>=0; i++){
            int didSwap=0;
            for(int j=0; j<i; j++){
                if(j+1<n && nums[j]>nums[j+1]){
                    int temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    didSwap=1;
                }
            }
            if(didSwap==0) break;
        }
    }
};