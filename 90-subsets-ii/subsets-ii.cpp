class Solution {
public:
    void output(vector<int> nums, int n, int ind, set<vector<int>> &temp, vector<int> child){
        if(ind==n){
            sort(child.begin(), child.end());
            temp.insert(child);
            child.clear();
            return;
        }

        // take 
        child.push_back(nums[ind]);
        output(nums, n, ind+1, temp, child);
        child.pop_back();
        // not take
        output(nums, n, ind+1, temp, child);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> temp;
        vector<int> child;
        output(nums, n, 0, temp, child);
        //auto it:: iterator= temp.begin();
        vector<vector<int>> ans;
        for(auto it=temp.begin(); it!=temp.end(); it++){
            vector<int> v;
            v= *it;
            ans.push_back(v);
        }
        return ans;
    }
};