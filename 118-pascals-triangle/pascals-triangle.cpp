class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==1) {
            vector<int> v;
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        else if(numRows==2) {
            vector<int> v;
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        else{
            vector<int> v;
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
            int i= ans.size()-1;
            vector<int> temp;
            numRows-=2;
            while(numRows--){
                temp= ans[i];
                vector<int> vp;
                vp.push_back(1);
                for(int j=0; j<temp.size()-1; j++){
                    vp.push_back(temp[j]+temp[j+1]);
                }
                vp.push_back(1);
                ans.push_back(vp);
                i++;
            }
            return ans;
        }
    }
};