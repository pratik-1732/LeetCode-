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
    TreeNode* output(TreeNode* root, int val){
        if(root==NULL){
            root= new TreeNode(val);
            return root;
        }
        if(val>root->val){
            if(root->right) output(root->right, val);
            else{
                root->right= new TreeNode(val);
                return root;
            }
        }
        else{
            if(root->left) output(root->left, val);
            else{
                root->left= new TreeNode(val);
                return root;
            }
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return output(root, val);
    }
};