class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if( i+1<nums.size()  && nums[i]!=nums[i+1])
                ans.push_back(nums[i]);
        }
        ans.push_back(nums[nums.size()-1]);
        int k=ans.size();
        //assert k == expectedNums.length;
        for (int i = 0; i < k; i++) {
            nums[i] = ans[i];
        }

        return k;
    }
};