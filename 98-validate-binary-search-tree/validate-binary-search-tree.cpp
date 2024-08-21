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
    bool output(TreeNode* root, long long mini, long long maxi){
        if(root==NULL) return true;

        if(root->val<=mini || root->val>=maxi) return false;

        return output(root->left, mini, (long long)root->val) && output(root->right, (long long)root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        long long mini=LLONG_MIN, maxi= LLONG_MAX;
        return output(root, mini, maxi);
    }
};