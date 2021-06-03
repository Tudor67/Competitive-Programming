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
    pair<int, int> maxSum(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        
        if(root->left == NULL && root->right == NULL){
            return {0, root->val};
        }
        
        pair<int, int> leftSum = maxSum(root->left);
        pair<int, int> rightSum = maxSum(root->right);
        int maxSumWithoutRoot = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);
        int maxSumWithRoot = root->val + leftSum.first + rightSum.first;
        
        return {maxSumWithoutRoot, maxSumWithRoot};
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> sum = maxSum(root);
        return max(sum.first, sum.second);
    }
};