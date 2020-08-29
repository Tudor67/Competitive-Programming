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
    int dfs(TreeNode* node, bool is_left_subtree){
        if(node == NULL){
            return 0;
        }
        if(node->left == NULL && node->right == NULL){
            return is_left_subtree * node->val;
        }
        return dfs(node->left, true) + dfs(node->right, false);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};