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
    void dfs(TreeNode* root, int pathMin, int pathMax, int& maxDiff){
        if(root != nullptr){
            pathMin = min(pathMin, root->val);
            pathMax = max(pathMax, root->val);
            maxDiff = max(maxDiff, pathMax - pathMin);
            dfs(root->left, pathMin, pathMax, maxDiff);
            dfs(root->right,pathMin, pathMax, maxDiff);
        }
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        dfs(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
};