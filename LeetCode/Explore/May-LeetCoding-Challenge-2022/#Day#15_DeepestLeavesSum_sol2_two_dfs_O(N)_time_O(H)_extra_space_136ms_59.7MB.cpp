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
    int getMaxDepth(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
    }
    
    int computeDeepestLeavesSum(TreeNode* root, int depth, int maxDepth){
        if(root == NULL){
            return 0;
        }
        if(depth == maxDepth){
            return root->val;
        }
        return computeDeepestLeavesSum(root->left, depth + 1, maxDepth) + 
               computeDeepestLeavesSum(root->right, depth + 1, maxDepth);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = getMaxDepth(root);
        return computeDeepestLeavesSum(root, 0, maxDepth);
    }
};