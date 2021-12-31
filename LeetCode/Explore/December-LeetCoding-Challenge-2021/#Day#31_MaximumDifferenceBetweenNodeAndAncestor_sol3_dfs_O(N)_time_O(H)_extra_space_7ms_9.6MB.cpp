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
    void dfs(TreeNode* node, int minVal, int maxVal, int& maxDiff){
        if(node != NULL){
            minVal = min(minVal, node->val);
            maxVal = max(maxVal, node->val);
            maxDiff = max(maxDiff, maxVal - minVal);
            dfs(node->left, minVal, maxVal, maxDiff);
            dfs(node->right, minVal, maxVal, maxDiff);
        }
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        dfs(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
};