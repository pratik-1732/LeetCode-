class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int> ans;
        // for(int i=0; i<nums.size(); i++){
        //     if( i+1<nums.size()  && nums[i]!=nums[i+1])
        //         ans.push_back(nums[i]);
        // }
        // ans.push_back(nums[nums.size()-1]);
        set<int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.insert(nums[i]);
        }
        
        //assert k == expectedNums.length;
        vector<int> temp;
        set<int>::iterator it;
         for (it = ans.begin(); it != ans.end(); it++){
    	    //cout << *it << " ";
            temp.push_back(*it);
        }
        int k=temp.size();
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }

        return k;
    }
};