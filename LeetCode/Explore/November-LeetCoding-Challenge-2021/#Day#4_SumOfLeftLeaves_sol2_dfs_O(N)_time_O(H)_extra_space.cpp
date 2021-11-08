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
    void dfs(TreeNode* root, bool isLeftChild, int& leftLeavesSum){
        if(root != NULL){
            if(root->left == NULL && root->right == NULL && isLeftChild){
                leftLeavesSum += root->val;
            }
            dfs(root->left, true, leftLeavesSum);
            dfs(root->right, false, leftLeavesSum);
        }
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        dfs(root, false, leftLeavesSum);
        return leftLeavesSum;
    }
};