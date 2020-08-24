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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        unordered_map<TreeNode*, bool> vis;
        stack<TreeNode*> st;
        if(root != NULL){
            st.push(root);
            vis[root] = true;
        }
        
        while(!st.empty()){
            TreeNode* node = st.top();
            
            while(node->left != NULL && !vis[node->left]){
                node = node->left;
                st.push(node);
                vis[node] = true;
            }
            
            st.pop();
            answer.push_back(node->val);
            
            if(node->right != NULL){
                st.push(node->right);
            }
        }
        
        return answer;
    }
};