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
    void dfs(TreeNode* root, int leftLen, int rightLen, int& res){
        if(root == nullptr){
            return;
        }
        res = max(res, max(leftLen, rightLen));
        dfs(root->left, rightLen + 1, 0, res);
        dfs(root->right, 0, leftLen + 1, res);
    }

public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, 0, 0, res);
        return res;
    }
};