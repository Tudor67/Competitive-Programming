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
        while(node != NULL){
            st.push(node);
            node = node->left;
        }
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        addLeftPath(root, st);
        
        TreeNode* newRoot = st.top();
        TreeNode* pred = NULL;

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            if(pred != NULL){
                node->left = NULL;
                pred->right = node;
            }
            pred = node;
            
            addLeftPath(node->right, st);
        }
        
        return newRoot;
    }
};