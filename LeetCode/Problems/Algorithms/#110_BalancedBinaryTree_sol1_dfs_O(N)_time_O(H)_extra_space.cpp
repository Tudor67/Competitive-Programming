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
    int checkHeight(TreeNode* root, bool& isBalanced){
        if(root == NULL){
            return 0;
        }
        int leftHeight = 1 + checkHeight(root->left, isBalanced);
        int rightHeight = 1 + checkHeight(root->right, isBalanced);
        if(abs(leftHeight - rightHeight) >= 2){
            isBalanced = false;
        }
        return max(leftHeight, rightHeight);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        checkHeight(root, isBalanced);
        return isBalanced;
    }
};