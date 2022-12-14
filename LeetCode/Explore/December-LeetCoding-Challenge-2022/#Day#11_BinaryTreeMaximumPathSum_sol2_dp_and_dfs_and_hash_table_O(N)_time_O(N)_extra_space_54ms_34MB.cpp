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
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& maxPathSumStartingAt, int& maxPathSum){
        if(node == nullptr){
            maxPathSumStartingAt[nullptr] = 0;
        }else{
            dfs(node->left, maxPathSumStartingAt, maxPathSum);
            dfs(node->right, maxPathSumStartingAt, maxPathSum);
            maxPathSumStartingAt[node] = node->val + max({0, maxPathSumStartingAt[node->left],
                                                             maxPathSumStartingAt[node->right]});
            maxPathSum = max(maxPathSum, node->val + max(0, maxPathSumStartingAt[node->left])
                                                   + max(0, maxPathSumStartingAt[node->right]));
        }
    }

public:
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, int> maxPathSumStartingAt;
        int maxPathSum = root->val;
        dfs(root, maxPathSumStartingAt, maxPathSum);
        return maxPathSum;
    }
};