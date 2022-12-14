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
    int maxPathSumStartingAt(TreeNode* node, int& maxPathSum){
        if(node == nullptr){
            return 0;
        }
        int maxPathSumStartingWithLeftChild  = maxPathSumStartingAt(node->left, maxPathSum);
        int maxPathSumStartingWithRightChild = maxPathSumStartingAt(node->right, maxPathSum);
        maxPathSum = max(maxPathSum, node->val + max(0, maxPathSumStartingWithLeftChild)
                                               + max(0, maxPathSumStartingWithRightChild));
        return node->val + max({0, maxPathSumStartingWithLeftChild, maxPathSumStartingWithRightChild});
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = root->val;
        maxPathSumStartingAt(root, maxPathSum);
        return maxPathSum;
    }
};