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
private:
    void addRightPath(TreeNode* node, stack<TreeNode*>& st){
        while(node != NULL){
            st.push(node);
            node = node->right;
        }
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> st;
        
        addRightPath(root, st);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            sum += node->val;
            node->val = sum;
            
            addRightPath(node->left, st);
        }
        
        return root;
    }
};