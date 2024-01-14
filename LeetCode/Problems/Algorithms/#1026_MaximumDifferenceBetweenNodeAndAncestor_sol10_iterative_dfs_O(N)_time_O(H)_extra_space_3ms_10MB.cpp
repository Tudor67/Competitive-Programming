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
            TreeNode* node = get<0>(st.top());
            int minVal = get<1>(st.top());
            int maxVal = get<2>(st.top());
            st.pop();

            maxDiff = max(maxDiff, max(node->val - minVal, maxVal - node->val));

            for(TreeNode* child: {node->right, node->left}){
                if(child != nullptr){
                    st.push({child, min(minVal, child->val), max(maxVal, child->val)});
                }
            }
        }

        return maxDiff;
    }
};