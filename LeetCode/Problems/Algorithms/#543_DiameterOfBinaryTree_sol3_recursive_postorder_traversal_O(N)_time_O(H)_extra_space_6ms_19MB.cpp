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
    int dfs(TreeNode* node, int& diameter){
        if(node == nullptr){
            return 0;
        }
        int leftMaxHeight = dfs(node->left, diameter);
        int rightMaxHeight = dfs(node->right, diameter);
        diameter = max(diameter, leftMaxHeight + rightMaxHeight);
        return 1 + max(leftMaxHeight, rightMaxHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};