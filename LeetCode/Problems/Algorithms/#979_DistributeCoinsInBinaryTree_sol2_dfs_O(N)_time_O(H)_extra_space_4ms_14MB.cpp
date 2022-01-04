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
    int computeExcess(TreeNode* root, int& moves){
        if(root == NULL){
            return 0;
        }
        int leftExcess = computeExcess(root->left, moves);
        int rightExcess = computeExcess(root->right, moves);
        moves += abs(leftExcess) + abs(rightExcess);
        return root->val - 1 + leftExcess + rightExcess;
    }
    
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        computeExcess(root, moves);
        return moves;
    }
};