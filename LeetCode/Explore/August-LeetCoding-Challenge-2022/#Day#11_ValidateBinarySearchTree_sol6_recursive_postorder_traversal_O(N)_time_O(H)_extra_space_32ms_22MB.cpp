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
    pair<int, int> postorderTraversal(TreeNode* root, bool& isValid){
        if(root == nullptr){
            return {0, 0};
        }
        
        if(root->left == nullptr && root->right == nullptr){
            return {root->val, root->val};
        }
        
        pair<int, int> leftSubtreeMinMax = postorderTraversal(root->left, isValid);
        pair<int, int> rightSubtreeMinMax = postorderTraversal(root->right, isValid);
        
        if((root->left != nullptr && leftSubtreeMinMax.second >= root->val) ||
           (root->right != nullptr && root->val >= rightSubtreeMinMax.first)){
            isValid = false;
        }
        
        pair<int, int> treeMinMax = {root->val, root->val};
        if(root->left != nullptr){
            treeMinMax.first = min(treeMinMax.first, leftSubtreeMinMax.first);
            treeMinMax.second = max(treeMinMax.second, leftSubtreeMinMax.second);
        }
        if(root->right != nullptr){
            treeMinMax.first = min(treeMinMax.first, rightSubtreeMinMax.first);
            treeMinMax.second = max(treeMinMax.second, rightSubtreeMinMax.second);
        }
        
        return treeMinMax;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        postorderTraversal(root, isValid);
        return isValid;
    }
};