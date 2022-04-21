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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* prevRoot = new TreeNode(INT_MIN, NULL, root);
        
        stack<pair<TreeNode*, TreeNode*>> st;
        st.emplace(prevRoot, root);
        while(!st.empty()){
            TreeNode* parent = st.top().first;
            TreeNode* node = st.top().second;
            st.pop();
            
            if(node == NULL){
                continue;
            }
            
            if(node->val < low){
                if(parent->left == node){
                    parent->left = node->right;
                }else{
                    parent->right = node->right;
                }
                TreeNode* nextNode = node->right;
                node->right = NULL;
                st.emplace(parent, nextNode);
            }else if(high < node->val){
                if(parent->left == node){
                    parent->left = node->left;
                }else{
                    parent->right = node->left;
                }
                TreeNode* nextNode = node->left;
                node->left = NULL;
                st.emplace(parent, nextNode);
            }else{
                st.emplace(node, node->right);
                st.emplace(node, node->left);
            }
        }
        
        root = prevRoot->right;
        prevRoot->right = NULL;
        delete prevRoot;
        
        return root;
    }
};