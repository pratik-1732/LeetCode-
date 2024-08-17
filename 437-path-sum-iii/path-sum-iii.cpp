// #define int long long
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
    void output(TreeNode* root, vector<long long> path, long long &cnt, int targetSum){
        if(root==NULL) return;

        path.push_back(root->val);
        output(root->left, path, cnt, targetSum);
        output(root->right, path, cnt, targetSum);

        long long len= path.size();
        long long sum=0;
        for(int i=len-1; i>=0; i--){
            sum+=path[i];
            if(sum==targetSum) cnt++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> path;
        long long cnt=0;
        output(root, path, cnt, targetSum);
        return cnt;
    }
};