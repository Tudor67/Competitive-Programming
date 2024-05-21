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
    bool isLeaf(TreeNode* node){
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* prevPostorderNode = nullptr;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* node = st.top();

            if(isLeaf(node) ||
               (node->right == prevPostorderNode && prevPostorderNode != nullptr) ||
               (node->right == nullptr && node->left == prevPostorderNode)){
                if(isLeaf(node->left) && node->left->val == target){
                    node->left = nullptr;
                }
                if(isLeaf(node->right) && node->right->val == target){
                    node->right = nullptr;
                }
                st.pop();
                prevPostorderNode = node;
            }else{
                if(node->right != nullptr){
                    st.push(node->right);
                }
                if(node->left != nullptr){
                    st.push(node->left);
                }
            }
        }

        if(isLeaf(root) && root->val == target){
            return nullptr;
        }
        return root;
    }
};