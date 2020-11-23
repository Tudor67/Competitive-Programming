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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            if(low <= node->val && node->val <= high){
                sum += node->val;
            }

            if(node->val > low && node->left != NULL){
                st.push(node->left);
            }

            if(node->val < high && node->right != NULL){
                st.push(node->right);
            }
        }
        
        return sum;
    }
};