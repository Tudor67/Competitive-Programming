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
    int sumRootToLeaf(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        if(root != NULL){
            st.emplace(root, root->val);
        }
        
        int sum = 0;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int num = st.top().second;
            st.pop();
            
            if(node->left == NULL && node->right == NULL){
                sum += num;
            }
            
            for(TreeNode* child: {node->right, node->left}){
                if(child != NULL){
                    st.emplace(child, 2 * num + child->val);
                }
            }
        }
        
        return sum;
    }
};