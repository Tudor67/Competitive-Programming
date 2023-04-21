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
    int longestZigZag(TreeNode* root) {
        int res = 0;

        stack<tuple<TreeNode*, int, int>> st;
        st.push({root, 0, 0});

        while(!st.empty()){
            TreeNode* node = get<0>(st.top());
            int leftLen = get<1>(st.top());
            int rightLen = get<2>(st.top());
            st.pop();

            res = max(res, max(leftLen, rightLen));

            if(node->right != nullptr){
                st.push({node->right, 0, leftLen + 1});
            }
            if(node->left != nullptr){
                st.push({node->left, rightLen + 1, 0});
            }
        }

        return res;
    }
};