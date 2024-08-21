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
    TreeNode* connect(TreeNode* root){
       if(root->right==NULL) return root;
       return connect(root->right);
    }
    TreeNode* change(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        else{
            TreeNode* rightChild= root->right;
            TreeNode* rightMost= connect(root->left);
            rightMost->right= rightChild;
            return root->left;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        
        if(root->val==key) return change(root);

        TreeNode* temp= root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left= change(root->left);
                }
                else{
                    root= root->left;
                }
            }
            else{
                if(root->right && root->right->val==key){
                    root->right= change(root->right);
                }
                else{
                    root= root->right;
                }
            }
        }
        return temp;
    }
};