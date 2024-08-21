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

// class Solution {
// public:
//     // bool output(TreeNode* root, long long mini, long long maxi){
//     //     if(root==NULL) return true;

//     //     if(root->val<=mini || root->val>=maxi) return false;

//     //     return output(root->left, mini, (long long)root->val) && output(root->right, (long long)root->val, maxi);
//     // }
//     // bool isValidBST(TreeNode* root) {
//     //     long long mini=LLONG_MIN, maxi= LLONG_MAX;
//     //     return output(root, mini, maxi);
//     // }
// };

class Solution {
public:
    vector<int> nodes;
    void inorder(TreeNode* root) {
        if (root->left) inorder(root->left);
        nodes.push_back(root->val);
        if (root->right) inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i] >= nodes[i+1]) return false;
        }
        return true;
    }
};