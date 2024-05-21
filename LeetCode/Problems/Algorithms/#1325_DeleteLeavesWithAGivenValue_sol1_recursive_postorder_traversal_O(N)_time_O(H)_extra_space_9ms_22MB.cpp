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
    void removeLeafNodes(TreeNode* parent, TreeNode* node, int target){
        if(node == nullptr){
            return;
        }
        
        removeLeafNodes(node, node->left, target);
        removeLeafNodes(node, node->right, target);

        if(node->left == nullptr && node->right == nullptr && node->val == target){
            if(parent->left == node){
                parent->left = nullptr;
            }else{
                parent->right = nullptr;
            }
        }
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        removeLeafNodes(root, root->left, target);
        removeLeafNodes(root, root->right, target);

        if(root->left == nullptr && root->right == nullptr && root->val == target){
            return nullptr;
        }

        return root;
    }
};