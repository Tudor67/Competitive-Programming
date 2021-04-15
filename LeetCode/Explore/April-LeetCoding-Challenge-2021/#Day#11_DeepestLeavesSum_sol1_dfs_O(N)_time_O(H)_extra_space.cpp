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
    void dfs(TreeNode* root, int depth, int& maxDepth, int& sum){
        if(root == NULL){
            return;
        }
        if(depth > maxDepth){
            maxDepth = depth;
            sum = 0;
        }
        if(depth == maxDepth){
            sum += root->val;
        }
        dfs(root->left, depth + 1, maxDepth, sum);
        dfs(root->right, depth + 1, maxDepth, sum);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxDepth = 0;
        dfs(root, 1, maxDepth, sum);
        return sum;
    }
};