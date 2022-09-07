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
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* leftPrunedChild = pruneTree(root->left);
        TreeNode* rightPrunedChild = pruneTree(root->right);
        root->left = leftPrunedChild;
        root->right = rightPrunedChild;
        if(root->val == 0 && leftPrunedChild == nullptr && rightPrunedChild == nullptr){
            return nullptr;
        }
        return root;
    }
};