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
    TreeNode* pruneTree(TreeNode* root) {
        vector<pair<TreeNode*, TreeNode*>> reversePostOrderParentsAndNodes;
        stack<pair<TreeNode*, TreeNode*>> st;
        st.emplace(nullptr, root);
        
        while(!st.empty()){
            TreeNode* parent = st.top().first;
            TreeNode* node = st.top().second;
            st.pop();
            
            reversePostOrderParentsAndNodes.emplace_back(parent, node);
            
            if(node->left != nullptr){
                st.emplace(node, node->left);
            }
            if(node->right != nullptr){
                st.emplace(node, node->right);
            }
        }
        
        const int N = reversePostOrderParentsAndNodes.size();
        for(int i = N - 1; i >= 0; --i){
            TreeNode* parent = reversePostOrderParentsAndNodes[i].first;
            TreeNode* node = reversePostOrderParentsAndNodes[i].second;
            if(node->val == 0 && node->left == nullptr && node->right == nullptr){
                if(parent == nullptr){
                    return nullptr;
                }
                if(parent->left == node){
                    parent->left = nullptr;
                }else{
                    parent->right = nullptr;
                }
            }
        }
        
        return root;
    }
};