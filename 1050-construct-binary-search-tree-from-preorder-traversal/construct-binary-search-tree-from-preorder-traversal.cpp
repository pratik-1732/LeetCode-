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
    TreeNode* output(vector<int>& preorder, int &ind, int bound){
        if(ind>=preorder.size() || preorder[ind]>bound) return NULL;

        int element= preorder[ind]; ind++;
        TreeNode* root= new TreeNode(element);

        root->left= output(preorder, ind, root->val);
        root->right= output(preorder, ind, bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return output(preorder, ind, INT_MAX);
    }
};