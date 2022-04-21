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
    void inorder(TreeNode* node, TreeNode*& pred, TreeNode*& newRoot){
        if(node != NULL){
            inorder(node->left, pred, newRoot);
            if(pred != NULL){
                node->left = NULL;
                pred->right = node;
            }
            pred = node;
            if(newRoot == NULL){
                newRoot = node;
            }
            inorder(node->right, pred, newRoot);
        }
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pred = NULL;
        TreeNode* newRoot = NULL;
        inorder(root, pred, newRoot);
        return newRoot;
    }
};