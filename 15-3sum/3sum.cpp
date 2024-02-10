class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n=nums.size();
         set<vector<int>> ans;
         sort(nums.begin(), nums.end());
         for(int i=0; i<n; i++){
            int a=i+1,b=n-1;
            if(i>0 && nums[i-1]==nums[i]) continue;
            while(a<b){
                int sum=nums[i]+nums[a]+nums[b];
                if(sum==0){
                    ans.insert({nums[i],nums[a],nums[b]});
                    a++;
                }
                else if(sum>0){
                    b--;
                }
                else a++;
            }
         }
         vector<vector<int>> temp;
         for(auto i: ans){
                temp.push_back(i);
         }
         return temp;
        
    }
};