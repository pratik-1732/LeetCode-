class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>> ans;
	int index=0;
	for(auto i: nums){
		ans.push_back(make_pair(i,index++));
	}
	sort(ans.begin(), ans.end());
	int i=0, j=ans.size()-1;
	while(i<j){
		if(ans[i].first+ans[j].first==target){
			vector<int> v;
			v.push_back(ans[i].second);
			v.push_back(ans[j].second);
			return v;
			i++;
		}
		else if(ans[i].first+ans[j].first>target){
			j--;
		}
		else i++;
	}
	return {};
    }
};