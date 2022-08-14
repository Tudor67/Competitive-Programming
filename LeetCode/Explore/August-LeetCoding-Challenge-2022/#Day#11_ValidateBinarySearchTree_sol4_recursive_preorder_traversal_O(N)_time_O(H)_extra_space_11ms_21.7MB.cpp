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
    bool isValidBST(TreeNode* root, long long l, long long r){
        if(root == nullptr){
            return true;
        }
        if(root->val < l || r < root->val){
            return false;
        }
        return isValidBST(root->left, l, root->val - 1LL) &&
               isValidBST(root->right, root->val + 1LL, r);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};