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
    void inorder(vector<int> &in, TreeNode* root){
        if(root==NULL) return;
        inorder(in, root->left);
        in.push_back(root->val);
        inorder(in, root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(in, root);
        int l=0, r=in.size()-1;
        int sum=0;
        while(l<r){
            if(in[l]+in[r]==k) return true;
            else if(in[l]+in[r]>k) r--;
            else l++;
        }
        return false;
    }
};