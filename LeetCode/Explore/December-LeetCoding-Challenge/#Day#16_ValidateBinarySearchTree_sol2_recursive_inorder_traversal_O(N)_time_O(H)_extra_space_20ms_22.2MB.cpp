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
    void inorder(TreeNode* root, long long& prevVal, bool& isValid){
        if(root == NULL || !isValid){
            return;
        }
        inorder(root->left, prevVal, isValid);
        isValid = isValid && (prevVal < root->val);
        prevVal = root->val;
        inorder(root->right, prevVal, isValid);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        long long prevVal = INT_MIN - 1LL;
        bool isValid = true;
        inorder(root, prevVal, isValid);
        return isValid;
    }
};