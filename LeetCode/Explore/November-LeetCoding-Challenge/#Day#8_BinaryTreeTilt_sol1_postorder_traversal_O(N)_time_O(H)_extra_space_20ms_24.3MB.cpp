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
    int getSum(TreeNode* root, int& tiltSum){
        if(root == NULL){
            return 0;
        }
        int leftSum = getSum(root->left, tiltSum);
        int rightSum = getSum(root->right, tiltSum);
        tiltSum += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
    
public:
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        getSum(root, tiltSum);
        return tiltSum;
    }
};