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
    void updateStack(stack<TreeNode*>& st, TreeNode* node){
        while(node != nullptr){
            st.push(node);
            node = node->right;
        }
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> st;
        int sum = 0;

        updateStack(st, root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            sum += node->val;
            node->val = sum;

            updateStack(st, node->left);
        }

        return root;
    }
};