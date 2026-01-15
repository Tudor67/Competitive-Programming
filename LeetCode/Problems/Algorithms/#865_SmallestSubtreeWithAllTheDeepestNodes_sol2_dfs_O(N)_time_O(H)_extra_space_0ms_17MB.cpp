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
    int dfs(TreeNode* node, int depth, int& maxDepth, TreeNode*& res){
        if(node == nullptr){
            return depth - 1;
        }

        int leftMaxDepth = dfs(node->left, depth + 1, maxDepth, res);
        int rightMaxDepth = dfs(node->right, depth + 1, maxDepth, res);

        maxDepth = max(maxDepth, max(leftMaxDepth, rightMaxDepth));

        if(leftMaxDepth == rightMaxDepth && leftMaxDepth == maxDepth){
            res = node;
        }

        return max(leftMaxDepth, rightMaxDepth);
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = -1;
        TreeNode* res = nullptr;
        dfs(root, 0, maxDepth, res);
        return res;
    }
};