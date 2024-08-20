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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans=0;
        while(!q.empty()){
            long long mini= q.front().second;
            long long size= q.size();
            long long first, last;
            for(long long i=0; i<size; i++){
                long long temp= q.front().second-mini;
                TreeNode* front= q.front().first;
                q.pop();
                if(i==0) first= temp;
                if(i==size-1) last= temp;
                if(front->left) q.push({front->left, 2*temp+1});
                if(front->right) q.push({front->right, 2*temp+2});
            }
            ans= max(ans, last-first+1);
        }
        return ans;
    }
};