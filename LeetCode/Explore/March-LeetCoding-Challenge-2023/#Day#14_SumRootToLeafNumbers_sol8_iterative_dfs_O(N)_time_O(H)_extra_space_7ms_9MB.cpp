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
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        stack<pair<TreeNode*, int>> st;
        if(root != nullptr){
            st.push({root, 0});
        }

        while(!st.empty()){
            TreeNode* node = st.top().first;
            int num = st.top().second;
            st.pop();

            num = num * 10 + node->val;

            if(node->left == nullptr && node->right == nullptr){
                sum += num;
            }

            if(node->right != nullptr){
                st.push({node->right, num});
            }
            if(node->left != nullptr){
                st.push({node->left, num});
            }
        }

        return sum;
    }
};