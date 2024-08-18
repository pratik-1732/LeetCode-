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
    int findPos(int ele, vector<int>& inorder, int n){
        for(int i=0; i<n; i++){
            if(inorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &ind, int start, int end, int n){
        if(ind>=n || start>end) return NULL;

        int element= preorder[ind++];
        TreeNode* temp= new TreeNode(element);

        int position= findPos(element, inorder, n);

        temp->left= solve(preorder, inorder, ind, start, position-1, n);
        temp->right= solve(preorder, inorder, ind, position+1, end, n);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= preorder.size();
        int ind=0;
        TreeNode* ans= solve(preorder, inorder, ind, 0, n-1, n);
        return ans;
    }
};