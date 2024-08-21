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
    // void output(TreeNode* root, int k, int &cnt, int &ans){
    //     if(root==NULL) return;

    //     output(root->left, k, cnt, ans);
    //     cnt++;
    //     if(cnt==k){
    //         ans= root->val;
    //         return;
    //     }
    //     output(root->right, k, cnt, ans);
    // }
     void output(TreeNode* root, vector<int> &inorder){
        if(root==NULL) return;

        inorder.push_back(root->val);
        output(root->left, inorder);
        output(root->right, inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        // int cnt=0, ans=-1;
        // output(root, k, cnt, ans);
        // return ans;

        vector<int> inorder;
        output(root, inorder);
        sort(inorder.begin(), inorder.end());
        return inorder[k-1];
    }
};