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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, 1);
        
        int answer = 0;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int depth = st.top().second;
            st.pop();
            
            answer = max(answer, depth);
            
            if(node->left != NULL){
                st.emplace(node->left, depth + 1);
            }
            if(node->right != NULL){
                st.emplace(node->right, depth + 1);
            }
        }
        
        return answer;
    }
};