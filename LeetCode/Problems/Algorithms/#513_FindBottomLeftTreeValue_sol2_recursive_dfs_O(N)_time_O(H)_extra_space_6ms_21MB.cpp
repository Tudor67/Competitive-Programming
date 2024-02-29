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
    void dfs(int level, TreeNode* node, int& maxLevel, int& leftmostValue){
        if(node != nullptr){
            if(maxLevel < level){
                maxLevel = level;
                leftmostValue = node->val;
            }
            dfs(level + 1, node->left, maxLevel, leftmostValue);
            dfs(level + 1, node->right, maxLevel, leftmostValue);
        }
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;
        int leftmostValue = 0;
        dfs(0, root, maxLevel, leftmostValue);
        return leftmostValue;
    }
};