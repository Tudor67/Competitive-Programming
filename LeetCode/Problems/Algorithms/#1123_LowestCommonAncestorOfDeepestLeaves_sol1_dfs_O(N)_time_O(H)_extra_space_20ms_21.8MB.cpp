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
    int getMaxDepth(TreeNode* root, int depth, int& globalMaxDepth, TreeNode*& lca){
        if(root == NULL){
            return depth;
        }
        int leftMaxDepth = getMaxDepth(root->left, depth + 1, globalMaxDepth, lca);
        int rightMaxDepth = getMaxDepth(root->right, depth + 1, globalMaxDepth, lca);
        globalMaxDepth = max({leftMaxDepth, rightMaxDepth, globalMaxDepth});
        if(leftMaxDepth == rightMaxDepth && rightMaxDepth == globalMaxDepth){
            lca = root;
        }
        return max(leftMaxDepth, rightMaxDepth);
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* lca = NULL;
        int globalMaxDepth = 0;
        getMaxDepth(root, 0, globalMaxDepth, lca);
        return lca;
    }
};