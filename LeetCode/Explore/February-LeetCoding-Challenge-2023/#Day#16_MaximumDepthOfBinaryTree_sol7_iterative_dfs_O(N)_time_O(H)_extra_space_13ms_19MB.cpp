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
    int maxDepth(TreeNode* root) {
        int res = 0;

        stack<pair<TreeNode*, int>> st;
        if(root != nullptr){
            st.push({root, 1});
        }

        while(!st.empty()){
            TreeNode* node = st.top().first;
            int depth = st.top().second;
            st.pop();

            res = max(res, depth);

            if(node->right != nullptr){
                st.push({node->right, depth + 1});
            }
            if(node->left != nullptr){
                st.push({node->left, depth + 1});
            }
        }

        return res;
    }
};