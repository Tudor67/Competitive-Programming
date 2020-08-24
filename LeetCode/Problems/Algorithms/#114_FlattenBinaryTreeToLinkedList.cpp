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
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(node != NULL){
            if(node->left != NULL){
                if(node->right != NULL){
                    st.push(node->right);
                }
                node->right = node->left;
                node->left = NULL;
                node = node->right;
            }else{
                if(node->right == NULL && !st.empty()){
                    node->right = st.top();
                    st.pop();
                }
                node = node->right;
            }
        }
    }
};