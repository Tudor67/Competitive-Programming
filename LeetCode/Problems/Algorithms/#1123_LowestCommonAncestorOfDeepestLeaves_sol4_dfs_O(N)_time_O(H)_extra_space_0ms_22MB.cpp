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
    int dfs(int depth, TreeNode* root, pair<int, TreeNode*>& depthLCA){
        if(root == nullptr){
            return depth - 1;
        }

        int lMaxDepth = dfs(depth + 1, root->left, depthLCA);
        int rMaxDepth = dfs(depth + 1, root->right, depthLCA);
        if(lMaxDepth == rMaxDepth && depthLCA.first <= rMaxDepth){
            depthLCA = {rMaxDepth, root};
        }

        return max(lMaxDepth, rMaxDepth);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int, TreeNode*> depthLCA = {0, root};
        dfs(0, root, depthLCA);
        return depthLCA.second;
    }
};