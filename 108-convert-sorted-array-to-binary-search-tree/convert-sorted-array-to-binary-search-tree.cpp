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
    // void output(vector<int> nums, int n, TreeNode* &temp, int l, int r){
    //     if(l>r) return;
    //     int mid= l+(r-l)/2;
    //     temp= new TreeNode(nums[mid]);
    //     output(nums, n, temp, l, mid-1);
    //     output(nums, n, temp, mid+1, r);
    // }
    TreeNode* output(vector<int> nums, int l, int r){
        if(l>r) return NULL;
        int mid= l+(r-l)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= output(nums, l, mid-1);
        root->right= output(nums, mid+1, r);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n= nums.size();
        // int l=0, r=n-1;

        // int mid= l+(r-l)/2;
        // TreeNode* root= new TreeNode(nums[mid]);
        // output(nums, n, root->left, l, mid-1);
        // output(nums, n, root->right, mid+1, r);
        // return root;
        int start=0, end=n-1;
        return output(nums, start, end);
    }
};