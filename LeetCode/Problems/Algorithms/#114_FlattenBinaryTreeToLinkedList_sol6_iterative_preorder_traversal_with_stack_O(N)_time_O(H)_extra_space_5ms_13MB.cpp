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
        
        TreeNode* prevNode = NULL;
        while(!st.empty()){
            TreeNode* node = st.top();
            TreeNode* leftChild = node->left;
            TreeNode* rightChild = node->right;
            st.pop();
            
            if(prevNode != NULL){
                prevNode->left = NULL;
                prevNode->right = node;
            }
            prevNode = node;
            
            if(rightChild != NULL){
                st.push(rightChild);
            }
            if(leftChild != NULL){
                st.push(leftChild);
            }
        }
    }
};