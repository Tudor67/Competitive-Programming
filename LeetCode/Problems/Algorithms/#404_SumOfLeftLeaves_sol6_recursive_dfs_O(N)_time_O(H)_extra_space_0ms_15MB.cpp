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
    void dfs(TreeNode* node, bool isLeftChild, int& leftLeavesSum){
        if(node != nullptr){
            if(isLeftChild && node->left == nullptr && node->right == nullptr){
                leftLeavesSum += node->val;
            }
            dfs(node->left, true, leftLeavesSum);
            dfs(node->right, false, leftLeavesSum);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        dfs(root, false, leftLeavesSum);
        return leftLeavesSum;
    }
};