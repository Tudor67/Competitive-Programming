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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if(root != nullptr){
            st.push(root);
        }

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            swap(node->left, node->right);

            if(node->right != nullptr){
                st.push(node->right);
            }
            if(node->left != nullptr){
                st.push(node->left);
            }
        }

        return root;
    }
};