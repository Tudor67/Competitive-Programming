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
        int sum = 0;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node == nullptr){
                continue;
            }

            if(low <= node->val && node->val <= high){
                sum += node->val;
                st.push(node->right);
                st.push(node->left);
            }else if(node->val < low){
                st.push(node->right);
            }else if(high < node->val){
                st.push(node->left);
            }
        }

        return sum;
    }
};