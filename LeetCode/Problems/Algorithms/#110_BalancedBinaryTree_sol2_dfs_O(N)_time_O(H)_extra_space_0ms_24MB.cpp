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
    int dfs(const TreeNode* node, bool& isBalancedTree){
        if(node == nullptr || !isBalancedTree){
            return 0;
        }
        int leftMaxHeight = dfs(node->left, isBalancedTree);
        int rightMaxHeight = dfs(node->right, isBalancedTree);
        if(abs(leftMaxHeight - rightMaxHeight) >= 2){
            isBalancedTree = false;
        }
        return 1 + max(leftMaxHeight, rightMaxHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;
        dfs(root, isBalancedTree);
        return isBalancedTree;
    }
};