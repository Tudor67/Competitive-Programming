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
    void recoverTree(TreeNode* root) {
        TreeNode* pred = NULL;
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        
        stack<TreeNode*> st;
        addLeftPath(root, st);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            if(pred != NULL && pred->val > node->val){
                if(node1 == NULL){
                    node1 = pred;
                }
                node2 = node;
            }
            
            pred = node;
            
            addLeftPath(node->right, st);
        }
        
        swap(node1->val, node2->val);
    }
};