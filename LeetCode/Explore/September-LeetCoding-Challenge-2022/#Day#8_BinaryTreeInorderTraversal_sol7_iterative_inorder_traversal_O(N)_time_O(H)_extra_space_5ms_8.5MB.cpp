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
    void addLeftPath(TreeNode* node, stack<TreeNode*>& st){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderValues;
        stack<TreeNode*> st;
        addLeftPath(root, st);
        
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            inorderValues.push_back(node->val);
            
            addLeftPath(node->right, st);
        }
        
        return inorderValues;
    }
};