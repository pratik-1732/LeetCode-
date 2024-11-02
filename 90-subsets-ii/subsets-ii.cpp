class Solution {
public:
    void output(vector<int>& nums, int ind, set<vector<int>> &st, vector<int> &temp){
        if(ind>=nums.size()){
            vector<int> temp2= temp;
            sort(temp2.begin(), temp2.end());
            st.insert(temp2);
            temp2.clear();
            return;
        }

        temp.push_back(nums[ind]);
        output(nums, ind+1, st, temp);
        temp.pop_back();
        output(nums, ind+1, st, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        output(nums, 0, st, temp);

        vector<vector<int>> ans;
        for(auto it=st.begin(); it!=st.end(); it++){
            ans.push_back(*it);
        }

        return ans;
    }
};