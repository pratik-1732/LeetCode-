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
    stack<TreeNode*> stN;
    stack<TreeNode*> stB;

    void pushInStackN(TreeNode* node){
        while(node!=NULL) {
            stN.push(node);
            node= node->left;
        }
    }
    void pushInStackB(TreeNode* node){
        while(node!=NULL) {
            stB.push(node);
            node= node->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        pushInStackN(root); pushInStackB(root);
        int low= next();
        int high= before();
        while(low!=high){
            if(!hasNextN() || !hasNextB()) return false;
            if(low+high==k) return true;
            else if(low+high>k){
                high= before();
            }
            else{
                low=next();
            }
        }
        return false;
    }
    int next(){
        TreeNode* temp= stN.top();
        stN.pop();
        if(temp->right) pushInStackN(temp->right);
        return temp->val;
    }
    int before(){
        TreeNode* temp= stB.top();
        stB.pop();
        if(temp->left) pushInStackB(temp->left);
        return temp->val;
    }
    bool hasNextN(){
        if(!stN.empty()) return true;
        return false;
    }
    bool hasNextB(){
        if(!stB.empty()) return true;
        return false;
    }
};