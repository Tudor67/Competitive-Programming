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
    void dfs(TreeNode* node, int depth, int& res){
        if(node != nullptr){
            if(node->left == nullptr && node->right == nullptr){
                res = min(res, depth);
            }
            dfs(node->left, depth + 1, res);
            dfs(node->right, depth + 1, res);
        }
    }

public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int res = INT_MAX;
        dfs(root, 1, res);

        return res;
    }
};