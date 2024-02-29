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
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;
        int leftmostValue = 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int level = st.top().second;
            st.pop();

            if(maxLevel < level){
                maxLevel = level;
                leftmostValue = node->val;
            }

            if(node->right != nullptr){
                st.push({node->right, level + 1});
            }
            if(node->left != nullptr){
                st.push({node->left, level + 1});
            }
        }

        return leftmostValue;
    }
};