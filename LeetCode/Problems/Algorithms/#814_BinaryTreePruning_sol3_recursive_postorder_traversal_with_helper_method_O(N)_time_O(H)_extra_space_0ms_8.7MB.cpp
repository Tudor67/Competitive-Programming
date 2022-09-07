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
    int countOnes(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        
        int leftOnes = countOnes(node->left);
        int rightOnes = countOnes(node->right);
        
        if(leftOnes == 0){
            node->left = nullptr;
        }
        if(rightOnes == 0){
            node->right = nullptr;
        }
        
        return (int)(node->val == 1) + leftOnes + rightOnes;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        int ones = countOnes(root);
        
        if(ones >= 1){
            return root;
        }
        return nullptr;
    }
};