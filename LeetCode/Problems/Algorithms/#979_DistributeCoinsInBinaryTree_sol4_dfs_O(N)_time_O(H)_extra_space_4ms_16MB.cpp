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
    pair<int, int> dfs(TreeNode* node, int& moves){
        if(node == nullptr){
            return {0, 0};
        }

        pair<int, int> l = dfs(node->left, moves);
        pair<int, int> r = dfs(node->right, moves);

        int subtreeSize = l.second + 1 + r.second;
        int subtreeCoins = l.first + node->val + r.first;

        moves += max(0, subtreeCoins - subtreeSize);
        moves += max(0, subtreeSize - subtreeCoins);

        return {subtreeCoins, subtreeSize};
    }

public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};