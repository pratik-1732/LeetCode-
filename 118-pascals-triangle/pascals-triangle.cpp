class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1}, {1,1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        int n= numRows-2;
        int j= 1;
        while(n--){
            vector<int> temp;
            temp.push_back(1);
            vector<int> check= ans[j];
            int len= check.size();
            for(int i=0; i<len-1; i++){
                temp.push_back(check[i]+check[i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};