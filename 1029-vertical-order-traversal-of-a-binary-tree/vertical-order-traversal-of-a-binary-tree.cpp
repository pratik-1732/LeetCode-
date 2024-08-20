/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    static bool comp(pair<int ,int>a, pair<int ,int>b){
        if(a.second<b.second) return true;
        else if(a.second==b.second){
            return a.first>=b.first;
        }
        else return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL) return ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp= q.front();
            q.pop();

            TreeNode* tempNode= temp.first;
            int hd= temp.second.first;
            int level= temp.second.second;
            // cout<<tempNode->val<<" "<<hd<<" "<<level<<endl;
            mp[hd][level].push_back(tempNode->val);
            if(tempNode->left) q.push({tempNode->left, {hd-1, level+1}});
            if(tempNode->right) q.push({tempNode->right, {hd+1, level+1}});
        }
       
        for(auto i: mp){
            vector<int> v;
            for(auto j: i.second){
                vector<int>& vec = j.second;
                sort(vec.begin(), vec.end());
                // v.insert(v.end(), vec.begin(), vec.end());
                for(auto k: vec) v.push_back(k);
            }
            // sort(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;

        // vector<vector<int>> res;
        // vector<pair<int, pair<int, int>>> ans;
        // if(root==NULL) return res;

        // queue<pair<int, pair<TreeNode* ,int>>> q;
        // q.push({0,{root,0}});
        // while(!q.empty()){
        //     pair<int, pair<TreeNode* ,int>> temp= q.front();
        //     q.pop();

        //     TreeNode* tempNode= temp.second.first;
        //     int hd= temp.second.second;
        //     int level= temp.first;

        //     ans.push_back({tempNode->val, hd});
        //     if(tempNode->left) q.push({tempNode->left, hd-1});
        //     if(tempNode->right) q.push({tempNode->right, hd+1});
        // }
        // sort(ans.begin(), ans.end(), comp);
        //  int len= ans.size();
        
        // vector<int> temp;
        // if(len==1){
        //     temp.push_back(ans[0].first);
        //     res.push_back(temp);
        //     return res;
        // }
        // for(int i=0; i<ans.size()-1; i++){
        //     if(ans[i].second==ans[i+1].second) temp.push_back(ans[i].first);
        //     else{
        //         temp.push_back(ans[i].first);
        //         res.push_back(temp);
        //         temp.clear();
        //     }
        // }
       
        //     if(ans[len-1].second==ans[len-2].second){
        //         temp.push_back(ans[len-1].first);
        //         res.push_back(temp);
        //     }
        //     else{
        //         // res.push_back(temp);
        //         vector<int> vp;
        //         vp.push_back(ans[len-1].first);
        //         res.push_back(vp);

        //     }
        // return res;
    }
};