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
    array<int, 3> getSumCountResult(TreeNode* node){
        if(node == nullptr){
            return {0, 0, 0};
        }
        array<int, 3> leftChildArr = getSumCountResult(node->left);
        array<int, 3> rightChildArr = getSumCountResult(node->right);
        int sum = node->val + leftChildArr[0] + rightChildArr[0];
        int count = 1 + leftChildArr[1] + rightChildArr[1];
        int result = (int)(sum / count == node->val) + leftChildArr[2] + rightChildArr[2];
        return {sum, count, result};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        return getSumCountResult(root)[2];
    }
};