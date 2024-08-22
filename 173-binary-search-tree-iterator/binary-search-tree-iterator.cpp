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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushInStack(TreeNode* node, stack<TreeNode*> &st){
        while(node!=NULL){
            st.push(node);
            node= node->left;
        }
    }
    BSTIterator(TreeNode* root) {
       
        pushInStack(root, st);
    }
    
    int next() {
        TreeNode* temp= st.top();
        st.pop();
        if(temp->right){
            pushInStack(temp->right, st);
        }
        return temp->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */