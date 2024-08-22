/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void output(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root->val==p->val || root->val==q->val){
            ans=root; return;
        }

        if(p->val < root->val && q->val < root->val) output(root->left, p, q, ans);
        else if(p->val > root->val && q->val > root->val) output(root->right, p, q, ans);
        else if((p->val > root->val && q->val < root->val) || (p->val < root->val && q->val > root->val)){
            ans= root;
            return;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
         output(root, p, q, ans);
         return ans;
    }
};