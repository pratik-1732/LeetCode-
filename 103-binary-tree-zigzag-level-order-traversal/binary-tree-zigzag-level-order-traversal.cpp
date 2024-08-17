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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL) return ans;

        bool flag= true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int len= q.size();
            vector<int> temp(len);
            for(int i=0; i<len; i++){
                TreeNode* frontNode= q.front();
                q.pop();

                if(flag){
                    temp[i]= frontNode->val;
                }
                else{
                    temp[len-i-1]= frontNode->val;
                }
                
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            flag= !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};