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
private:
    stack<TreeNode*> st;
    
public:
    BSTIterator(TreeNode* root) {
        for(TreeNode* node = root; node != NULL; node = node->left){
            st.push(node);
        }
    }
    
    int next() {
        TreeNode* root = st.top();
        st.pop();
        int val = root->val;
        for(TreeNode* node = root->right; node != NULL; node = node->left){
            st.push(node);
        }
        return val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */