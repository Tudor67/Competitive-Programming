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
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while(!st.empty()){
            TreeNode* node = st.top().first;
            bool isLeftChild = st.top().second;
            st.pop();

            if(isLeftChild && node->left == nullptr && node->right == nullptr){
                leftLeavesSum += node->val;
            }
            
            if(node->right != nullptr){
                st.push({node->right, false});
            }
            if(node->left != nullptr){
                st.push({node->left, true});
            }
        }

        return leftLeavesSum;
    }
};