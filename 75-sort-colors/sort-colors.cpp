class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==1) cout<<nums[0];
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(j+1<n && nums[j]>nums[j+1] ){
                        int temp=nums[j];
                        nums[j]=nums[j+1];
                        nums[j+1]=temp;
                    }
                }
            }
            for(auto i: nums){
                cout<<i<<" ";
            }
        }
    }
};