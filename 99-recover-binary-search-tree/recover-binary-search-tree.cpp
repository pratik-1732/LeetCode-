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
    void check(TreeNode* &root, vector<int> &in, int &ind){
        if(ind>=in.size() || root==NULL) return;

        check(root->left, in, ind);
        if(root->val!=in[ind]) root->val= in[ind];
        ind++;
        check(root->right, in, ind);
    }
    void recoverTree(TreeNode* root) {
        vector<int> in;
        inorder(in, root);
        sort(in.begin(), in.end());
        int ind=0;
        check(root, in, ind);
    }
};