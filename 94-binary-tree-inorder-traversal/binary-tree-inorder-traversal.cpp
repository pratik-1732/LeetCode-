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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> q;
        TreeNode* temp= root;
        while(true){
            if(temp!=NULL){
                q.push(temp);
                temp= temp->left;
            }
            else{
                if(q.empty()) break;
                temp= q.top();
                q.pop();
                inorder.push_back(temp->val);
                temp= temp->right;
            }
        }
        return inorder;
    }
};