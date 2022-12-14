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
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;

        stack<tuple<TreeNode*, int, int>> st;
        st.push({root, root->val, root->val});

        while(!st.empty()){
            const tuple<TreeNode*, int, int> T = st.top();
            st.pop();

            TreeNode* node = get<0>(T);
            int pathMin = get<1>(T);
            int pathMax = get<2>(T);

            maxDiff = max(maxDiff, pathMax - pathMin);

            if(node->right != nullptr){
                st.push({node->right, min(pathMin, node->right->val), max(pathMax, node->right->val)});
            }
            if(node->left != nullptr){
                st.push({node->left, min(pathMin, node->left->val), max(pathMax, node->left->val)});
            }
        }

        return maxDiff;
    }
};