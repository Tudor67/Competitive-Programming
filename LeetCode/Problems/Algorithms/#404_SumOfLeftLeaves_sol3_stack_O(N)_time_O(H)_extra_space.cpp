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
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, false});
        
        while(!st.empty()){
            TreeNode* node = st.top().first;
            bool isLeftChild = st.top().second;
            st.pop();
            
            if(node->left == NULL && node->right == NULL && isLeftChild){
                leftLeavesSum += node->val;
            }
            
            if(node->left != NULL){
                st.push({node->left, true});
            }
            if(node->right != NULL){
                st.push({node->right, false});
            }
        }
        
        return leftLeavesSum;
    }
};