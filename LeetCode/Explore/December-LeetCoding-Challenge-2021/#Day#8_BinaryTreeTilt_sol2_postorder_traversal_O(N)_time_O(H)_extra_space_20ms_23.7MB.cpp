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
    int dfs(TreeNode* root, int& tiltSum){
        if(root == NULL){
            return 0;
        }
        int leftSum = dfs(root->left, tiltSum);
        int rightSum = dfs(root->right, tiltSum);
        tiltSum += abs(leftSum - rightSum);
        return leftSum + root->val + rightSum;
    }
    
public:
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        dfs(root, tiltSum);
        return tiltSum;
    }
};