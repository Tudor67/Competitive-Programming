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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int res = INT_MAX;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while(!st.empty()){
            TreeNode* node = st.top().first;
            int depth = st.top().second;
            st.pop();

            if(node->left == nullptr && node->right == nullptr){
                res = min(res, depth);
            }

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