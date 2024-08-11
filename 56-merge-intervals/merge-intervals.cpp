class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n= intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        // for(auto i: intervals){
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        vector<int> v(2);
        v[0]= intervals[0][0], v[1]= intervals[0][1];
        for(int i=1; i<n; i++){
            if(v[1]<intervals[i][0]){
                ans.push_back(v);
                v[0]= intervals[i][0];
                v[1]= intervals[i][1];
            }
            else if(v[1]>=intervals[i][1]){
                continue;
            }
            else{
                v[1]= intervals[i][1];
            }
        }
        ans.push_back(v);
        return ans;
    }
};