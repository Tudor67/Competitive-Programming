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
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 0;
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, root->val);
        
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int prefMax = st.top().second;
            st.pop();
            
            if(prefMax <= node->val){
                goodNodesCount += 1;
            }
            
            if(node->right != nullptr){
                st.emplace(node->right, max(prefMax, node->val));
            }
            if(node->left != nullptr){
                st.emplace(node->left, max(prefMax, node->val));
            }
        }
        
        return goodNodesCount;
    }
};