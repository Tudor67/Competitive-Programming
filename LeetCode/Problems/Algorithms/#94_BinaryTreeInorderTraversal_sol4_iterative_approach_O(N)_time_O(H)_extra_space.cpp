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
        while(node != NULL){
            st.push(node);
            node = node->left;
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderNodes;
        stack<TreeNode*> st;
        updateStack(root, st);
        while(!st.empty()){
            TreeNode* node = st.top(); st.pop();
            inorderNodes.push_back(node->val);
            updateStack(node->right, st);
        }
        return inorderNodes;
    }
};