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
        stack<TreeNode*> st;
        if(root != NULL){
            st.push(root);
        }
        
        TreeNode* prevNode = root;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            if(node != root){
                prevNode->left = NULL;
                prevNode->right = node;
                prevNode = node;
            }
            
            for(TreeNode* nextNode: {node->right, node->left}){
                if(nextNode != NULL){
                    st.push(nextNode);
                }
            }
        }
    }
};