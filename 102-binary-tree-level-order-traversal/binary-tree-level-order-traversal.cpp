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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> temp= q.front();
            q.pop();

            TreeNode* tempNode= temp.first;
            int level= temp.second;

            mp[level].push_back(tempNode->val);
            if(tempNode->left) q.push({tempNode->left, level+1});
            if(tempNode->right) q.push({tempNode->right, level+1});
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};