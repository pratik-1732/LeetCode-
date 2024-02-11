class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int cnt=0;
        // vector<int> ans;
        // for(auto i: nums){
        //     if(i==0) cnt++;
        //     else ans.push_back(i);
        // }
        // while(cnt--){
        //     ans.push_back(0);
        // }
        // for(auto i: ans){
        //     cout<<i<<" ";
        // }
        
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0) cnt++;
        }
        int ep=n,sp=0;
       
            for(int i=0; i<n; i++){
                if(cnt==0) break;
                if(nums[i]==0){
                    cnt--;
                    for(int j=i; j<ep; j++){
                        if(j+1>=ep) break;
                        int temp=nums[j];
                        nums[j]=nums[j+1];
                        nums[j+1]=temp;
                    }
                    ep--;
                    i--;
                }
            }
        
        
        //  while(cnt--){
        //     ans.push_back(0);
        // }
         for(auto i: nums){
            cout<<i<<" ";
        }

        
    }
};