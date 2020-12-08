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
    void inorder(TreeNode* root, TreeNode*& pred){
        if(root != NULL){
            inorder(root->left, pred);
            root->left = NULL;
            pred->right = root;
            pred = pred->right;
            inorder(root->right, pred);
        }
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = new TreeNode();
        TreeNode* pred = newRoot;
        inorder(root, pred);
        return newRoot->right;
    }
};