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
 class answer{
    public:
    int maxi, mini, sum;
    answer(int maxi, int mini, int sum){
        this->maxi= maxi;
        this->mini= mini;
        this->sum= sum;
    }
 };

class Solution {
public:
    answer output(TreeNode* root, int &ans){
       if(!root) return answer(INT_MIN, INT_MAX, 0);

        auto left= output(root->left, ans);
        auto right= output(root->right, ans);

        if(root->val>left.maxi && root->val<right.mini){
            ans= max(ans, max(left.sum, max(right.sum, left.sum+right.sum+root->val)));
            return answer(max(root->val, right.maxi), min(root->val, left.mini), left.sum+right.sum+root->val);
        }
        return answer(INT_MAX, INT_MIN, max(left.sum, right.sum));
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        output(root, ans);
        return ans;
    }
};