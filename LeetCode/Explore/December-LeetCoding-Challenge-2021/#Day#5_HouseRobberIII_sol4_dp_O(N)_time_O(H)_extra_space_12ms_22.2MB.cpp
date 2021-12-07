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
    pair<int, int> computeMaxSum(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        
        pair<int, int> leftMaxSum = computeMaxSum(root->left);
        pair<int, int> rightMaxSum = computeMaxSum(root->right);
        
        int leftMaxSumWithRoot = leftMaxSum.first;
        int leftMaxSumWithoutRoot = leftMaxSum.second;
        int rightMaxSumWithRoot = rightMaxSum.first;
        int rightMaxSumWithoutRoot = rightMaxSum.second;
        
        return {root->val + leftMaxSumWithoutRoot + rightMaxSumWithoutRoot,
                max(leftMaxSumWithRoot, leftMaxSumWithoutRoot) + max(rightMaxSumWithRoot, rightMaxSumWithoutRoot)};
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> maxSum = computeMaxSum(root);
        return max(maxSum.first, maxSum.second);
    }
};