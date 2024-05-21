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
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& subtreeCoins,
             unordered_map<TreeNode*, int>& subtreeSize, int& moves){
        if(node == nullptr){
            return;
        }

        dfs(node->left, subtreeCoins, subtreeSize, moves);
        dfs(node->right, subtreeCoins, subtreeSize, moves);

        subtreeSize[node] = subtreeSize[node->left] + 1 + subtreeSize[node->right];
        subtreeCoins[node] = subtreeCoins[node->left] + node->val + subtreeCoins[node->right];

        moves += max(0, subtreeCoins[node] - subtreeSize[node]);
        moves += max(0, subtreeSize[node] - subtreeCoins[node]);
    }

public:
    int distributeCoins(TreeNode* root) {
        unordered_map<TreeNode*, int> subtreeCoins;
        unordered_map<TreeNode*, int> subtreeSize;
        int moves = 0;
        dfs(root, subtreeCoins, subtreeSize, moves);
        return moves;
    }
};