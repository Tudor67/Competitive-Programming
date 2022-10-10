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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> st;
        if(root != nullptr){
            st.emplace(root, root->val);
        }
        
        bool found = false;
        while(!st.empty() && !found){
            TreeNode* node = st.top().first;
            int sum = st.top().second;
            st.pop();
            
            if(node->left == nullptr && node->right == nullptr){
                found = found || (sum == targetSum);
            }
            
            if(node->right != nullptr){
                st.emplace(node->right, sum + node->right->val);
            }
            if(node->left != nullptr){
                st.emplace(node->left, sum + node->left->val);
            }
        }
        
        return found;
    }
};