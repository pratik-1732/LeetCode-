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
    int position(vector<int>& inorder, int n, int value){
        for(int i=0; i<n; i++){
            if(inorder[i]==value) return i;
        }
        return -1;
    }
    TreeNode* output( vector<int>& inorder, vector<int>& preorder, int &ind, int n, int start, int end){
        if(ind>=n || start>end) return NULL;

        int element= preorder[ind]; ind++;
        TreeNode* temp= new TreeNode(element);
        int pos= position(inorder, n, element);

        temp->left= output(inorder, preorder, ind, n, start, pos-1);
        temp->right= output(inorder, preorder, ind, n, pos+1, end);

        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        vector<int> inorder;
        inorder= preorder;
        sort(inorder.begin(), inorder.end());
        int ind=0;
        TreeNode* ans= output(inorder, preorder, ind, n, 0, n-1);
        return ans;
    }
};