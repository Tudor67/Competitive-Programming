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
    int maxDiff(TreeNode* root, int minVal, int maxVal){
        if(root == NULL){
            return maxVal - minVal;
        }
        minVal = min(root->val, minVal);
        maxVal = max(root->val, maxVal);
        int leftDiff = maxDiff(root->left, minVal, maxVal);
        int rightDiff = maxDiff(root->right, minVal, maxVal);
        return max(leftDiff, rightDiff);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxDiff(root, root->val, root->val);
    }
};