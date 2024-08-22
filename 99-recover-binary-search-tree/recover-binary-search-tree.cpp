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
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;

public:
    void inorder(TreeNode* root){
        if(root==NULL) return;

        inorder(root->left);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=middle=NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        if(first!=NULL && last!=NULL){
            TreeNode* temp= new TreeNode(first->val);
            first->val= last->val;
            last->val= temp->val;
        }
        else if(first!=NULL && middle!=NULL){
            TreeNode* temp= new TreeNode(first->val);
            first->val= middle->val;
            middle->val= temp->val;
        }
    }
};