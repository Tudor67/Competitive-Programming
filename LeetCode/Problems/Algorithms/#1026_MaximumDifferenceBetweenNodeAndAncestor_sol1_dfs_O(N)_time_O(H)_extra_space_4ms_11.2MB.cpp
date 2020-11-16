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
    void dfs(TreeNode* root, int minVal, int maxVal, int& maxDiff){
        if(root == NULL){
            return;
        }
        maxDiff = max({abs(minVal - root->val), abs(maxVal - root->val), maxDiff});
        minVal = min(root->val, minVal);
        maxVal = max(root->val, maxVal);
        dfs(root->left, minVal, maxVal, maxDiff);
        dfs(root->right, minVal, maxVal, maxDiff);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        dfs(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
};