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
private:
    void updateStack(TreeNode* node, stack<TreeNode*>& st){
        if(node->right != NULL){
            st.push(node->right);
        }
        if(node->left != NULL){
            st.push(node->left);
        }
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderNodes;
        stack<TreeNode*> st;
        if(root != NULL){
            st.push(root);
        }
        while(!st.empty()){
            TreeNode* node = st.top(); st.pop();
            preorderNodes.push_back(node->val);
            updateStack(node, st);
        }
        return preorderNodes;
    }
};