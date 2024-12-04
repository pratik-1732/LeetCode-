class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int ind=-1;
        for(int j=n-2; j>=0; j--){
            if(nums[j]<nums[j+1]) {
                ind= j;
                break;
            }
        }

        if(ind==-1){ 
            sort(nums.begin(), nums.end());
            return;
        }

        int minInd= -1;
        int diff= INT_MAX;
        for(int j=ind+1; j<nums.size(); j++){
            int temp= abs(nums[ind]-nums[j]);
            if(temp==0 || nums[j]<nums[ind]) continue;
            if(diff>temp){
                diff= temp;
                minInd= j;
            }
        }
        // cout<<ind<<" "<<minInd<<endl;
        swap(nums[ind], nums[minInd]);
        // for(auto it: nums) cout<<it<<" ";
        sort(nums.begin()+ind+1, nums.end());

    }
};