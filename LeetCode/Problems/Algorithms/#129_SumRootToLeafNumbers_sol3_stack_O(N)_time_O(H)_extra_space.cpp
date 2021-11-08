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
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        int sum = 0;
        
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int num = st.top().second;
            st.pop();
            
            if(node->left == NULL && node->right == NULL){
                sum += num;
            }else{
                if(node->left != NULL){
                    st.push({node->left, 10 * num + node->left->val});
                }
                if(node->right != NULL){
                    st.push({node->right, 10 * num + node->right->val});
                }
            }
        }
        
        return sum;
    }
};