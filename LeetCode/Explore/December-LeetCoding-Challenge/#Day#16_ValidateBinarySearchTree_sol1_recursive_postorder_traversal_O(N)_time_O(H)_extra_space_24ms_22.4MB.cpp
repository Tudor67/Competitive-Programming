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
    pair<long long, long long> minMaxCheck(TreeNode* root, bool& isValid){
        if(root == NULL || !isValid){
            return {1LL + INT_MAX, INT_MIN - 1LL};
        }
        
        if(root->left == NULL && root->right == NULL){
            return {root->val, root->val};
        }
        
        pair<long long, long long> leftP = minMaxCheck(root->left, isValid);
        pair<long long, long long> rightP = minMaxCheck(root->right, isValid);
        long long leftMin = leftP.first;
        long long leftMax = leftP.second;
        long long rightMin = rightP.first;
        long long rightMax = rightP.second;
        
        if(leftMax >= root->val || root->val >= rightMin){
            isValid = false;
        }
        
        return {min(leftMin, (long long)root->val), max((long long)root->val, rightMax)};
    }
    
public:
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        minMaxCheck(root, isValid);
        return isValid;
    }
};